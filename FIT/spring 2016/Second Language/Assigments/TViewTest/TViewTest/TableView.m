//
//  TableView.m
//  TViewTest
//
//  Created by Danilo Mendes on 4/3/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#import "TableView.h"
#import "ViewController.h"

@implementation TableView

-(void)viewDidLoad{
    [super viewDidLoad];
    
    self.title = @"Table";
    
    self.array = [[NSMutableArray alloc] init];
    
    for (int i=0; i<10; i++) {
        NSString *str = [[NSString alloc] initWithFormat:@"Title %d",i];
        NSString *substr = [[NSString alloc] initWithFormat:@"Subtitle %d",i];
        
        self.dic = [[NSMutableDictionary alloc] initWithObjects:@[str,substr] forKeys:@[@"Title",@"Subtitle"]];
        
        [self.array addObject:self.dic];
        
    }
    NSLog(@"oioi");
}

-(void)didReceiveMemoryWarning{
    [super didReceiveMemoryWarning];
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [self.array count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    NSString *identifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier forIndexPath:indexPath];
    
    
    NSDictionary *current = [self.array objectAtIndex:indexPath.row];
    
    NSString *title = [current objectForKey:@"Title"];
    NSString *sub = [current objectForKey:@"Subtitle"];
    
    cell.textLabel.text = title;
    cell.detailTextLabel.text = sub;
    
    return cell;
    
}

-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender{
    if ([segue.identifier isEqualToString:@"detail"]) {
        NSIndexPath *index = [self.tableView indexPathForSelectedRow];
        
        NSDictionary *dic = self.array[index.row];
        
        ViewController *v = segue.destinationViewController;
        
        [v setText:[dic valueForKey:@"Subtitle"]];
        
    }
}

@end
