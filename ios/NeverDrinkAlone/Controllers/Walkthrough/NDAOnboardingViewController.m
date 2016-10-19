//
//  NDAOnboardingViewController.m
//  NeverDrinkAlone
//
//  Created by Ayan Yenbekbay on 4/4/15.
//  Copyright (c) 2015 Ayan Yenbekbay. All rights reserved.
//

#import "NDAOnboardingViewController.h"

#import "NDAConstants.h"
#import "NDAOnboardingContentViewController.h"
#import "UIFont+NDASizes.h"
#import "UIView+AYUtils.h"

@interface NDAOnboardingViewController () <UIPageViewControllerDataSource, UIPageViewControllerDelegate, UIScrollViewDelegate>

@property (nonatomic) UIPageViewController *pageViewController;

@end

@implementation NDAOnboardingViewController

#pragma mark Initialization

- (instancetype)initWithContents:(NSArray *)contents {
  self = [super init];
  if (!self) {
    return nil;
  }

  self.edgesForExtendedLayout = UIRectEdgeNone;
  // Store the passed in view controllers array
  self.viewControllers = contents;
  // Set the default properties
  self.shouldFadeTransitions = NO;
  self.fadePageControlOnLastPage = NO;
  self.swipingEnabled = YES;
  self.hidePageControl = NO;
  self.allowSkipping = NO;
  self.skipHandler = ^{};
  // Create the initial exposed components so they can be customized
  self.pageControl = [UIPageControl new];
  self.skipButton = [UIButton new];

  return self;
}

#pragma mark View

- (void)viewDidLoad {
  [super viewDidLoad];
  // Now that the view has loaded, we can generate the content
  [self generateView];
}

- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
}

- (void)generateView {
  // Create our page view controller
  [self.view setBackgroundColor:self.backgroundColor ? : [UIColor blackColor]];
  self.pageViewController = [[UIPageViewController alloc] initWithTransitionStyle:UIPageViewControllerTransitionStyleScroll navigationOrientation:UIPageViewControllerNavigationOrientationHorizontal options:nil];
  self.pageViewController.view.frame = self.view.frame;
  self.pageViewController.view.backgroundColor = self.backgroundColor ? : [UIColor blackColor];
  self.pageViewController.delegate = self;
  self.pageViewController.dataSource = self.swipingEnabled ? self : nil;

  // Set the initial current page as the first page provided
  self.currentPage = [self.viewControllers firstObject];

  // More page controller setup
  [self.pageViewController setViewControllers:@[self.currentPage] direction:UIPageViewControllerNavigationDirectionForward animated:YES completion:nil];
  [self addChildViewController:self.pageViewController];
  [self.view addSubview:self.pageViewController.view];
  [self.pageViewController didMoveToParentViewController:self];

  // Create and configure the the page control
  if (!self.hidePageControl) {
    self.pageControl.frame = CGRectMake(0, self.view.height - kOnboardingBottomHeight, self.view.width, kOnboardingBottomHeight);
    self.pageControl.backgroundColor = self.pageControlColor ? : [UIColor colorWithWhite:0 alpha:0.5f];
    self.pageControl.numberOfPages = (NSInteger)self.viewControllers.count;
    self.pageControl.userInteractionEnabled = NO;
    [self.view addSubview:self.pageControl];
  }

  // If we allow skipping, setup the skip button
  if (self.allowSkipping) {
    self.skipButton.frame = CGRectMake(self.view.height - kOnboardingSkipButtonWidth, self.view.height - kOnboardingBottomHeight, kOnboardingSkipButtonWidth, kOnboardingBottomHeight);
    [self.skipButton setTitle:self.skipButtonText forState:UIControlStateNormal];
    self.skipButton.titleLabel.font = [UIFont fontWithName:kRegularFontName size:[UIFont mediumTextFontSize]];
    [self.skipButton addTarget:self action:@selector(performCompletionHandler) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.skipButton];
  }

  // If we want to fade the transitions, we need to tap into the underlying scrollview
  // so we can set ourself as the delegate, this is sort of hackish but the only current
  // solution I am aware of using a page view controller
  if (self.shouldFadeTransitions) {
    for (UIView *view in self.pageViewController.view.subviews) {
      if ([view isKindOfClass:[UIScrollView class]]) {
        [(UIScrollView *)view setDelegate:self];
      }
    }
  }

  // Set ourself as the delegate on all of the content views, to handle fading
  // and auto-navigation
  for (NDAOnboardingContentViewController *contentVC in self.viewControllers) {
    contentVC.delegate = self;
  }
}

#pragma mark Skipping

- (void)performCompletionHandler {
  self.skipHandler();
}

#pragma mark Setters

- (void)setTitleColor:(UIColor *)titleColor {
  for (NDAOnboardingContentViewController *contentVC in self.viewControllers) {
    contentVC.titleColor = titleColor;
  }
}

- (void)setSubtitleColor:(UIColor *)subtitleColor {
  for (NDAOnboardingContentViewController *contentVC in self.viewControllers) {
    contentVC.subtitleColor = subtitleColor;
  }
}

- (void)setTitleFontSize:(CGFloat)titleFontSize {
  for (NDAOnboardingContentViewController *contentVC in self.viewControllers) {
    contentVC.titleFontSize = titleFontSize;
  }
}

- (void)setSubtitleFontSize:(CGFloat)subtitleFontSize {
  for (NDAOnboardingContentViewController *contentVC in self.viewControllers) {
    contentVC.subtitleFontSize = subtitleFontSize;
  }
}

- (void)setPageControlColor:(UIColor *)pageControlColor {
  _pageControlColor = pageControlColor;
  self.pageControl.backgroundColor = pageControlColor;
}

- (void)setContinueButtonColor:(UIColor *)continueButtonColor {
  for (NDAOnboardingContentViewController *contentVC in self.viewControllers) {
    contentVC.continueButtonColor = continueButtonColor;
  }
}

#pragma mark UIPageViewControllerDataSource

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerBeforeViewController:(UIViewController *)viewController {
  // Return the previous view controller in the array unless we're at the beginning
  if (viewController == [self.viewControllers firstObject]) {
    return nil;
  } else {
    NSUInteger priorPageIndex = [self.viewControllers indexOfObject:viewController] - 1;
    return self.viewControllers[priorPageIndex];
  }
}

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerAfterViewController:(UIViewController *)viewController {
  // Return the next view controller in the array unless we're at the end
  if (viewController == [self.viewControllers lastObject]) {
    return nil;
  } else {
    NSUInteger nextPageIndex = [self.viewControllers indexOfObject:viewController] + 1;
    return self.viewControllers[nextPageIndex];
  }
}

#pragma mark UIPageViewControllerDelegate

- (void)pageViewController:(UIPageViewController *)pageViewController didFinishAnimating:(BOOL)finished previousViewControllers:(NSArray *)previousViewControllers transitionCompleted:(BOOL)completed {
  // If we haven't completed animating yet, we don't want to do anything because it could be cancelled
  if (!completed) {
    return;
  }
  // Get the view controller we are moving towards, then get the index, then set it as the current page
  // for the page control dots
  UIViewController *viewController = [pageViewController.viewControllers lastObject];
  NSUInteger newIndex = [self.viewControllers indexOfObject:viewController];
  self.pageControl.currentPage = (NSInteger)newIndex;
}

- (void)moveNextPage {
  NSUInteger indexOfNextPage = [self.viewControllers indexOfObject:self.currentPage] + 1;

  if (indexOfNextPage < self.viewControllers.count) {
    [self.pageViewController setViewControllers:@[self.viewControllers[indexOfNextPage]] direction:UIPageViewControllerNavigationDirectionForward animated:YES completion:nil];
    self.pageControl.currentPage = (NSInteger)indexOfNextPage;
  }
}

#pragma mark Page Scrolling

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
  // Calculate the percent complete of the transition of the current page given the
  // scrollview's offset and the width of the screen
  CGFloat percentComplete = (CGFloat)(fabs(scrollView.contentOffset.x - self.view.width) / self.view.width);

  // These cases have some funk results given the way this method is called, like stuff
  // just disappearing, so we want to do nothing in these cases
  if (self.upcomingPage == self.currentPage || percentComplete == 0) {
    return;
  }
  // Set the next page's alpha to be the percent complete, so if we're 90% of the way
  // scrolling towards the next page, its content's alpha should be 90%
  [self.upcomingPage updateAlpha:percentComplete];
  // Set the current page's alpha to the difference between 100% and this percent value,
  // so we're 90% scrolling towards the next page, the current content's alpha sshould be 10%
  [self.currentPage updateAlpha:1 - percentComplete];

  // If we want to fade the page control on the last page...
  if (self.fadePageControlOnLastPage) {
    // If the upcoming page is the last object, fade the page control out as we scroll.
    if (self.upcomingPage == [self.viewControllers lastObject]) {
      self.pageControl.alpha = 1 - percentComplete;
    }
    // Otherwise if we're on the last page and we're moving towards the second-to-last page, fade it back in.
    else if ((self.currentPage == [self.viewControllers lastObject]) && (self.upcomingPage == self.viewControllers[self.viewControllers.count - 2])) {
      self.pageControl.alpha = percentComplete;
    }
  }
}

@end
