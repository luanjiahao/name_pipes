#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include <cassert>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

#define NAMED_PIPE "./mypipe"

bool createFifo(const string &path)
{
    umask(0);
    int n = mkfifo(path.c_str(), 0666);
    if (n == 0)
        return true;
    else
    {
        cout << "error: " << errno << "err string: "<< strerror(errno) <<endl;
        return false;
    }
}

void removeFifo(const string &path)
{
    int n=unlink(path.c_str());
    assert(n==0);
    (void)n;
}

