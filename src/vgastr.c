// 彭东 @ 2021.01.09
// Source: https://gitee.com/lmos/cosmos/blob/master/lesson02/HelloOS/vgastr.c

void _strwrite(char *string) {
  char *p_strdst = (char *)(0xb8000);
  while (*string) {
    *p_strdst = *string++;
    p_strdst += 1;
    *p_strdst = 0x2; // color green
    p_strdst += 1;
  }
  return;
}

void printf(char *fmt, ...) {
  _strwrite(fmt);
  return;
}
