# short_minilibx

Quick set up for using minilibx in your project.

Add a struct s_short_minilibx to your own struct and provide desired settings :
```c
t_short_minilibx {
  void *mlx; // don't care
  void *win; // don't care
  int  width; // width in pixel
  int  height; // height in pixel
  void *image; // don't care
  /* function part */
  void *(*init)(void *self); // your optional init function
  int  *(*key)(int key, void *self); // your optional key handler function
  int  *(*mouse)(int button, int x, int y, void *self); // your optional mouse handler function
  int  *(*expose)(void *self); // your optional expose handler function
  int  *(*loop)(void *self); // your optional loop function
 
  char *error; // don't care if an error occur the error will be here
}
```

Add any numbers of images you want :
Implement a simple struct s_short_minilibx_image for each image you need.
```c
t_short_minilibx_image {
  int   width; // width of the image in pixel
  int   height; // height of the image in pixel
  
  int   xposition; // x position on the screen
  int   yposition; // y position on the screen ( note that the anchor of the screen is up left ).
  void  *img; // don't care
  int   **raw; // acces each pixel by image.raw[y][x] = color
  void  *next; // don't care
}
```

Call short_minilibx_init(void *const self, char *const title, int image_count, ...)
self -> your struct containing in first order a t_short_minilibx.
Note that self will be send to function.
title -> title of the screen
image_count -> specify how many image will be sent, for each image add a pointer to it.

For exiting just call short_minilibx_deinit();
and make a call to exit() if you have done all of your stuff before quitting.

## EXEMPLE :
```c
// header
typedef struct
{
  t_short_minilibx  self;
  t_short_minilibx_image  image;
  const char        *str;
}             mystruct;
// c file

void    func_init(mystruct *self)
{
  printf("before image put on screen ...");
}

int     main(void)
{
  static mystruct   mystruct_var =
  {
    {
      NULL, NULL, 1920, 1080, NULL,
      func_init, NULL, NULL, NULL, NULL, NULL
    },
    {
      1920, 1080, 0, 0, NULL, NULL, NULL
    },
    "this is my global struct"
  };
  short_minilibx_init(&mystructvar, "hello short_minilibx", 1, &mystructvar.image);
}
```
