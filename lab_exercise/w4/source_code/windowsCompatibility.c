#include "windowsCompatibility.h"

void enableWindowsCompatibility()
{
    /* Disable buffering on stdout - this is typically an issue when using Eclipse on Windows. */
    setvbuf(stdout, NULL, _IONBF, 0);

    /* Disable buffering on stderr just in case. */
    setvbuf(stderr, NULL, _IONBF, 0);
}
