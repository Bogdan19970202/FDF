
#include "../mandatory/fdf.h"
# include <stdio.h>

void* ft_realloc(void* p, size_t new_size, size_t old_size)
{
  void* tmp;
  printf("%s\n", (char*)p);
  tmp = (char *)malloc(new_size);
  if (tmp == NULL)
    return(NULL);
  ft_memmove(tmp, p, old_size);
  printf("%s\n", (char*)tmp);

  free(p);
  return (tmp);
}
int main(void)
{
  int fd;
  char* s;
  char** z;
  t_pix**  arr;
  int j, len, i;
  int counter;
  char  buf[2];
  t_pix*** arr_fin;

  len = 0;
  buf[0] = '1';
  s = buf;
  fd= open("./mandatory/elem-col.fdf", O_RDONLY);

  
  while (i > 0)
  {
    i = read(fd, buf, 1);
    if (buf[0] == '\n')
      len++;
  }
  close(fd);
  fd= open("./mandatory/elem-col.fdf", O_RDONLY);

  arr_fin = (t_pix ***)malloc(sizeof(t_pix**) * (len + 1));
  arr_fin[len] = NULL;
  buf[0] = '1';
  s = buf;
  counter = 0;
  // // z = (char *)ft_realloc(s, ft_strlen(s), 7);
  printf("%d", fd);
  
  while (s != NULL)
  {
    printf("%s", s);
    s = get_next_line(fd);
    if (s == NULL)
      break ;
    z = ft_split(s, ' ');

    i = 0;
    while (z[i] != NULL)
      i++;
    printf("%d", i);
    arr = (t_pix **)malloc(sizeof(t_pix *) * (i + 1));
    
    if (*arr == NULL)
    {
      printf("%ssalsm", (char *)(*arr));
      return(2);
    }

    // arr[i] = NULL;

    // i = 0; 
    // while (z[i] != NULL)
    // {
    //   arr[i] = (t_pix *)malloc(sizeof(t_pix));
    //   if (arr[i] == NULL)
    //     break ;
    //   // arr[i]->x = i;
    //   // arr[i]->y = counter;
    //   // arr[i]->end = 0;
    //   // arr[i]->z = *(ft_split(z[i], ',')[0]);
    //   // if ((ft_split(z[i], ',')[1]) != NULL)
    //   //   arr[i]->color = *(ft_split(z[i], ',')[0]);
    //   i++;
    // }
    // arr[i - 1]->end = 1;
    // arr_fin[counter] = arr; 


    counter ++;
    printf("%d", counter );
  }
  // // printf("%d", j );
  // printf("%s", (char *)arr_fin[len] );
  
  return 0;
}