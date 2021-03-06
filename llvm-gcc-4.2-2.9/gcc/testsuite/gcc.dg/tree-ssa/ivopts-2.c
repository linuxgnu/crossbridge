/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-ivopts-details" } */
/* LLVM LOCAL test not applicable */
/* { dg-require-fdump "" } */

long last_data_offset;
int store;
char *data;
  
f ()
{
  
  long data_offset = last_data_offset;
  char *p;
  
  for (p = data; *p; p++)
    {
      data_offset++;
      g (data_offset);
      store = data_offset + 1;
    }
}

/* We should only have two IVs.  */
/* { dg-final { scan-tree-dump-not "\\n  candidates \\d+, \\d+,\[^\\n\]*\\n\[^\\n\]*\\nFinal cost" "ivopts" } }  */
/* { dg-final { cleanup-tree-dump "ivopts" } }  */
