#include "comm.hpp"

using namespace std;

int main()
{
    bool r = createFifo(NAMED_PIPE);
    assert(r);
    (void)r;

    cout << "server begin" <<endl;
    int rfd = open(NAMED_PIPE, O_RDONLY);
    cout << "server end" << endl;
    if (rfd < 0)
        exit(1);

    // read
    char buffer[1024];
    while (true)
    {
        ssize_t s = read(rfd, buffer, sizeof(buffer) - 1);
        if (s > 0)
        {
            buffer[s] = 0;
            cout << "client->server# " << buffer << endl;
        }
        else if (s == 0)
        {
            cout << "client quit, me too!" << endl;
            break;
        }
        else
        {
            cout << "err string: " << strerror(errno) << endl;
            break;
        }
    }

    close(rfd);

    removeFifo(NAMED_PIPE);
    return 0;
}