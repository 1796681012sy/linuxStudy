#ifndef PROTO_H__
#define PROTO_H__
#define MAXN 1024
#define KEYPATH "/home/u/tmp"
#define KEYVA 'A'

struct msg_st{
  long type;
  char s[MAXN];
  int chinese;
  int math;
};

#endif
