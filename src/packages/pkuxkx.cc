#include "../lpc_incl.h"
#include "../comm.h"
#include "../file_incl.h"
#include "../file.h"
#include "../backend.h"
#include "../compiler.h"
#include "../main.h"
#include "../eoperators.h"
#include "../efuns_main.h"
#include "../efun_protos.h"
#include "../simul_efun.h"
#include "../add_action.h"
#include "../array.h"
#include "../master.h"
#include "../port.h"
#include "../array.h"

#include <iconv.h>


#ifdef PACKAGE_PKUXKX

char *translate(iconv_t tr, const char *input)
{
  size_t inlen = strlen(input) + 1;  
  char *output = 0, *output_pre;
  size_t outlen = 0, outlen_pre;

  if (!output) {
    output_pre = output = (char *)DMALLOC(inlen, TAG_PERMANENT, "gbutf8");
    outlen_pre = outlen = inlen;
  }

  while (inlen) {
    iconv(tr, (char **)&input, &inlen, &output, &outlen);

		if (E2BIG == errno) {
			errno = 0;
			outlen_pre *= 2;
			output = (char *)DREALLOC(output_pre, outlen_pre, TAG_PERMANENT, "gbutf8");
			if(!output) {
				FREE(output_pre);
				return 0;
			}
			output_pre = output;
			output = output_pre + (outlen_pre / 2 - outlen);
			outlen = outlen + outlen_pre / 2;
			continue;
		}
	}
  return output_pre;
}


void f_gb_to_utf8()
{
  char *text = (char *)sp->u.string;

  iconv_t t = iconv_open("UTF-8", "gbk");
  char *translated = translate(t, text);
	iconv_close(t);

  pop_stack();
  copy_and_push_string(translated);
	
}
void f_utf8_to_gb()
{
  char *text = (char *)sp->u.string;

  iconv_t t = iconv_open("gbk", "UTF-8");
  char *translated = translate(t, text);
	iconv_close(t);

  pop_stack();
  copy_and_push_string(translated);	
}
#endif

