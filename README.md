# short_minilibx

Quick set up for using minilibx in your project.

Add a struct s_short_minilibx to your own struct and provide desired settings :

t_short_minilibx {<br />
  void *mlx; // don't care<br />
  void *win; // don't care<br />
  int  width; // width in pixel<br />
  int  height; // height in pixel<br />
  void *image; // don't care<br />
  /* function part */<br />
  void *(*init)(void *self); // your optional init function<br />
  int  *(*key)(int key, void *self); // your optional key handler function<br />
  int  *(*mouse)(int button, int x, int y, void *self); // your optional mouse handler function<br />
  int  *(*expose)(void *self); // your optional expose handler function<br />
  int  *(*loop)(void *self); // your optional loop function<br />
  <br />
  char *error; // don't care if an error occur the error will be here<br />
}<br />
<br />
Add any numbers of images you want :<br />
Implement a simple struct s_short_minilibx_image for each image you need.<br />
<br />
t_short_minilibx_image {<br />
  int   width; // width of the image in pixel<br />
  int   height; // height of the image in pixel<br />
  <br />
  int   xposition; // x position on the screen<br /> 
  int   yposition; // y position on the screen ( note that the anchor of the screen is up left ).<br />
  void  *img; // don't care<br />
  int   **raw; // acces each pixel by image.raw[y][x] = color<br />
  void  *next; // don't care<br />
}<br />
<br />
Call short_minilibx_init(void *const self, char *const title, int image_count, ...)<br />
self -> your struct containing in first order a t_short_minilibx.<br />
Note that self will be send to function.<br />
title -> title of the screen<br />
image_count -> specify how many image will be sent, for each image add a pointer to it.<br />
<br />
For exiting just call short_minilibx_deinit();<br />
and make a call to exit() if you have done all of your stuff before quitting.<br />
<br />
## EXEMPLE :<br />
<br />
// header<br />
typedef struct<br />
{<br />
  t_short_minilibx  self;<br />
  t_short_minilibx_image  image;<br />
  const char        *str;<br />
}             mystruct;<br />
// c file<br />
<br />
void    func_init(mystruct *self)<br />
{<br />
  printf("before image put on screen ...");<br />
}<br />
<br />
int     main(void)<br />
{<br />
  static mystruct   mystruct_var =<br />
  {<br />
    {<br />
      NULL, NULL, 1920, 1080, NULL,<br />
      func_init, NULL, NULL, NULL, NULL, NULL<br />
    },<br />
    {<br />
      1920, 1080, 0, 0, NULL, NULL, NULL<br />
    },<br />
    "this is my global struct"<br />
  };<br />
  <br />
  short_minilibx_init(&mystructvar, "hello short_minilibx", 1, &mystructvar.image);<br /> 
}
