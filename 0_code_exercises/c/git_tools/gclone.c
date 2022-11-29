#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void run(char* exec, char* opt);

// clone URL [OPTIONS]
// OPTIONS:
//   -b   branch name
//   -o   output directory
//   -p   remote paths in repo (max to 10 paths)
//
// EXAMPLE:
//   gclone http://test/repo.git -b feature/foo -o repo_foo -p /examples -p /src
int main(int argc, char* argv[]){
  if (argc <= 1) { printf("no url given\n"); return 1; }

  // horrbile check for http / git first argument
  if (tolower(argv[1][0]) != 'h' && tolower(argv[1][0]) != 'g') { printf("incorrect url given!\n"); return 1; }

  char* rurl = argv[1];
  char* branch = NULL;
  char* outdir = NULL;
  char* path[10] = { NULL };
  int o;

  while ((o = getopt(argc, argv, "b:o:p:")) != -1){
    switch (o){
      case 'b':
        branch = optarg;
        break;
      case 'o':
        outdir = optarg;
        break;
      case 'p':
        for (int i = 0; i < 10; i++){
          if (!path[i]){
            path[i] = optarg;
            break;
          }
        }
        break;
    }
  }
  // printf("b = %s, o = %s\n", branch, outdir);

  for (int i = 0; i < 10; i++){
    if (!path[i]) break;
    printf("%d = %s\n", i, path[i]);
  }
  
  char gitcmd[256] = {0};
  strcpy(gitcmd, strcat("git clone ", rurl));
  // snprintf(gitcmd, 256, "git clone %s ", rurl);
  printf("%s\n", gitcmd);
  snprintf(gitcmd, 256, "%s --no-checkout --depth 1", gitcmd);
  printf("%s\n", gitcmd);
  // temp = strncat(temp, " --no-checkout --depth 1", 256);
  // strcpy(gitcmd, temp);
  // printf("%s\n", gitcmd);
  // if (branch) strcpy(gitcmd, strcat(strcat(gitcmd, " --branch "), branch));
  // printf("%s\n", gitcmd);
  // if (outdir) strcpy(gitcmd, strcat(strcat(gitcmd, " "), outdir));
  // printf("%s\n", gitcmd);
  // run("echo", gitcmd);

  char cmd[256] = {0};
  snprintf(cmd, 256, "%s .git", rurl);
  run("basename", cmd);

  // snprintf(cmd, 256, "%s && ls", outdir);
  // run("cd", cmd);

  // cd $outdir
  // for i; do git sparse-checkout set "$1"
  // git checkout $branch"

  return 0;
}

void run(char* exec, char* opt){
  if (!opt){ printf("incorrect usage of %s, no parameter!\n", exec); return; }

  static char command[256];
  snprintf(command, 256, "%s %s", exec, opt);
  // printf("Command: <<%s>>\n", command);
  FILE* fp = popen(command, "r");
  static char result[256];
  while (fgets(result, sizeof(result), fp) != 0)
  {
    result[strlen(result)-1] = '\0';
    printf("%s\n", result);
  }
  pclose(fp);
}
