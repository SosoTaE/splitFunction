#include <iostream>
#include "lb.h"

using namespace std;


int main() {
    Vector arr = split("a.b.c.d.e.r.d.f.t.h.d.as.d.f.r.f",".");

    print(arr);

    string joined = arr.join("&");

    print(joined);
    
}
