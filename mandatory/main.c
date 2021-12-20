
#include "../mandatory/fdf.h"
# include <stdio.h>
void ft_centr(double min_x, double max_x, double min_z, double max_z, double height, double width, t_pix ***arr_fin)
{
  double k, z_av, x_av;
  int i,j;

  i = 0;
  z_av = (max_z - min_z) / 2 + min_z;
  x_av = (max_x - min_x) / 2 + min_x;
  
  if ((max_x - min_x > width) || (max_z - min_z > height))
  {
    
    if ((max_x - min_x) / width > (max_z - min_z) / height)
    {
      printf("%f s", z_av );
      k = (max_x - min_x) / width; 
    }
    else
    {
      k = (max_z - min_z) / height;
    }  
    
    // printf("%s", arr_fin[0]);
    while (arr_fin[i] != NULL)
    {
      j = 0;
      // printf("%f salsam", k );
      while (arr_fin[i][j] != NULL)
      {
        arr_fin[i][j]->x = (arr_fin[i][j]->x - x_av) / k;
        arr_fin[i][j]->y = arr_fin[i][j]->y / k;
        arr_fin[i][j]->z = (arr_fin[i][j]->z - z_av) / k;
        printf("%f\n", arr_fin[i][j]->z);
        j++;
      }
      
      i++;
    }
  }
}
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
  // printf("%d", fd);
  
  while (s != NULL)
  {
    // printf("%s", s);
    s = get_next_line(fd);
    if (s == NULL)
      break ;
    z = ft_split(s, ' ');

    i = 0;
    while (z[i] != NULL)
      i++;
    // printf("\n%d\n", i);
    arr = (t_pix **)malloc(sizeof(t_pix *) * (i + 1));
    
    if (arr == NULL)
    {
      // printf("%ssalsm", (char *)(*arr));
      return(2);
    }

    arr[i] = NULL;

    i = 0; 
    while (z[i] != NULL)
    {
      arr[i] = (t_pix *)malloc(sizeof(t_pix));
      if (arr[i] == NULL)
        break ;
      arr[i]->x = i;
      arr[i]->y = counter;
      arr[i]->z =  ft_atoi((ft_split(z[i], ',')[0]));
      // printf("%s\n",ft_split(z[i], ',')[1]);
      // if (ft_strchr(z[i], ',') != NULL)
      //   arr[i]->color = *(ft_split(z[i], ',')[0]);
      // else
      //   arr[i]->color = 0xFFFFFF;
      // printf("%d\n",arr[i]->z);
      i++;
      
    }
    arr[i] = NULL;

    arr_fin[counter] = arr; 


    counter ++;
    // printf("%d", counter );
  }
  arr_fin[counter] = NULL;
  // // printf("%d", j );
  // printf("%s", (char *)arr_fin[len] );
  ft_centr(0, 9, 0,20, 5, 100, arr_fin);
  // printf("%d", j );
  return 0;
}