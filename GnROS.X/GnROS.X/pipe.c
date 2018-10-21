#include "pipe.h"
#include "kernel.h"

void create_pipe(pipe_t *p)
{
  p->pos_read   = 0;
  p->pos_write  = 0;
}

void write(pipe_t *p, byte msg)
{
  DGI();
  
  p->pipe_msgs[p->pos_write] = msg;
  p->pos_write = (p->pos_write + 1) % PIPE_SIZE;
  
  // Se posi��o de escrita for igual a pos. de leitura
  // bloqueia processo. N�o h� espa�o para escrita.
  if (p->pos_write == p->pos_read)
    dispatcher(W_PIPE);
  
  EGI();
}

void read(pipe_t *p, byte *msg)
{
  DGI();

  // Se posi��o de leitura for igual a pos. de escrita
  // bloqueia processo. N�o existe dado novo a ser lido.
  if (p->pos_write == p->pos_read)
    dispatcher(W_PIPE);
  
  *msg = p->pipe_msgs[p->pos_read];
  p->pos_read = (p->pos_read + 1) % PIPE_SIZE;
  
  // Chama o despachante para liberar eventuais
  // tarefas bloqueadas
  dispatcher(READY);
  
  EGI();
}

