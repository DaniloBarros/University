//
//  ViewController.m
//  TViewTest
//
//  Created by Danilo Mendes on 4/3/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.title = @"Details";
    [self.textLabel setText:self.text];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
