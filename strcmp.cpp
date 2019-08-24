/**
 * File              : strcmp.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 23.08.2019
 * Last Modified Date: 23.08.2019
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */

int strcmp(char const * a, char const * b) {
    while (*a) {
        if (*a != *b) {
            break;
        }
        a++; b++;
    }
    return *(unsigned char const *)a - *(unsigned char const*)b;
}
