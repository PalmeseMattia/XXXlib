#include<X11/Xlib.h>
#include<stdio.h>

int main(void)
{
    XEvent event;
    Display *d = XOpenDisplay(NULL);
    
    if(d == NULL){
        fprintf(stderr,"Connection to the X server failed.\n"); 
        return 1;
    }

    Window w = XCreateSimpleWindow(
        d,                  // display
        RootWindow(d, 0),   // window
        0,                  // x
        0,                  // y
        640,                // width
        480,                // height
        1,                  // border width
        BlackPixel(d, 0),   // border
        WhitePixel(d, 0)    // background
    );

    XSelectInput(d, w, ExposureMask | KeyPressMask); 
    
    XMapWindow(d, w);

    while (1) {
        XNextEvent(d, &event);
        if (event.type == KeyPress)
            break;
    }
    
    XDestroyWindow(d, w);
    XCloseDisplay(d);
    
    return 0;
}
