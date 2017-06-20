//
//  main.cpp
//  testFork
//
//  Created by Danilo Mendes on 9/15/15.
//  Copyright (c) 2015 Danilo Mendes. All rights reserved.
//

#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int num[] = {10, 20, 30 , 40};
    
    int *ptr;
    
    ptr = num;
    
    cout << *(ptr + 1);
    
    return 0;
}

/*

 int rc = fork();
 12 if (rc < 0) { // fork failed; exit
 13 fprintf(stderr, "fork failed\n");
 14 exit(1);
 15 } else if (rc == 0) { // child: redirect standard output to a file
 16 close(STDOUT_FILENO);
 17 open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
 18
 19 // now exec "wc"...
 20 char *myargs[3];
 21 myargs[0] = strdup("wc");
 22 myargs[1] = strdup("p4.c");
 23 myargs[2] = NULL;
 24 execvp(myargs[0], myargs);
 25 } else { // parent
 26 int wc = wait(NULL);
 27 }

*/