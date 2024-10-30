#include "comm.hpp"
using namespace std;

int main()
{
    cout << "client begin" << endl;
    int wfd = open(NAMED_PIPE, O_WRONLY);
    cout << "client end" << endl;
    if(wfd < 0) exit(1); 

    //write
    char buffer[1024];
    while(true)
    {
        cout << "Please Say# ";
        fgets(buffer, sizeof(buffer), stdin); // abcd\n
        if(strlen(buffer) > 0) buffer[strlen(buffer)-1] = 0;
        ssize_t n = write(wfd, buffer, strlen(buffer));
        assert(n == strlen(buffer));
        (void)n;
    }

    close(wfd);
    return 0;
}