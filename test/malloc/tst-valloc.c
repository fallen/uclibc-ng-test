/* Test case by Stephen Tweedie <sct@redhat.com>.  */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
#if __UCLIBC_SUSV2_LEGACY__
  char *p;
  int pagesize = getpagesize ();
  int i;

  p = valloc (pagesize);
  i = (long int) p;

  if ((i & (pagesize-1)) != 0)
    {
      fprintf (stderr, "Alignment problem: valloc returns %p\n", p);
      exit (1);
    }

  return 0;
#else
  return 23;
#endif
}
