#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../minishell.h"

int is_parent() 
{
  // Bu fonksiyon, çalışma durumunu değerlendirir ve uygun olduğu durumlarda program
  // exit fonksiyonu ile sonlanır.
  //Çalışma durumu, programın ana süreç mi yoksa bir alt süreç mi olduğudur. 
  //Ana süreç, bir kabuk tarafından başlatılan ilk süreçtir. 
  //Alt süreçler, ana süreç tarafından oluşturulan süreçlerdir.

  pid_t pid = getpid();// is_parent() fonksiyonu, 
  return pid == 1;		// getpid() işlevini kullanarak geçerli sürecin kimliğini elde eder. 
						// Eğer geçerli süreç ana süreç ise, fonksiyon 1 değerini döndürür. 
						// Eğer geçerli süreç bir alt süreç ise, fonksiyon 0 değerini döndürür.
}

int change_dir(char **input) 
{
  // Bu fonksiyon, programda CD (Change Directory) komutunun
  // işlemini yapar.

  if (input[1] != NULL) {
    // input[1] boş değilse, input[1] deki dizin adına geçmeyi deniyor.
    if (chdir(input[1]) == -1) 
	{
      perror("chdir()");
      return errno;

	//chdir() işlevi başarısız olursa, fonksiyon perror() işlevini kullanarak 
	//hatayı ekrana yazdırır ve errno değerini döndürür. 
	//errno değeri, hatanın nedenini gösteren bir sayısal koddur.
    }
  } 

  	else 
  	{
    // input[1] boş ise, HOME değişkeni içindeki ev dizinine geçmeyi deniyor.
    char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
      perror("getenv()");
      return ENOENT;
	}

    if (chdir(home_dir) == -1) 
	{
      perror("chdir()"); 
      return errno;
    }
  }

  // Eğer programın çalıştığı dizin ana dizin değilse (is_parent() fonksiyonu ile
  // kontrol ediliyor), program exit(errno) fonksiyonuyla sonlandırılıyor.

  if (!is_parent()) 
  {
    exit(errno);
  }

  return 0;
}

// int main(int argc, char **argv) 
// {
//   if (argc == 2) {
//     return change_dir(argv + 1);
//   } else {
//     printf("Yanlış kullanım! Kullanım: cd [yol]\n");
//     return -1;
//   }
// }


// int main() 
// {

//   char *input[] = {"cd", "/home/kullanici/"};
//   return change_dir(input);
// }

// int main(void) 
// {

//   char *home_dir = getenv("HOME");
//   char *desktop_dir = strcat(home_dir, "/Desktop");

//   int ret = change_dir((char *[]){ "cd", desktop_dir });

//   if (ret != 0) {
//     printf("CD komutu başarısız oldu. Hata kodu: %d\n", ret);
//   }

//   return 0;
// }


