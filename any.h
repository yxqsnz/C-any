#ifndef ANY_H
#define ANY_H

enum ctype { TYPE_CHAR, TYPE_CHAR_POINTER, TYPE_INT, TYPE_FLOAT };

struct any {
  enum ctype type;
  void *value;
};

typedef struct any any_t;
#define _any_concat(a, b) a##b
#define mkis(name, b)                                                          \
  int _any_concat(is, name)(any_t * it) { return it->type == b; }

#define typeof(t)                                                              \
  _Generic((t), int : TYPE_INT, char : TYPE_CHAR, char * : TYPE_CHAR_POINTER, float : TYPE_FLOAT)

#define anyify(a, t)                                                           \
  {                                                                            \
    void **it = malloc(sizeof((t)));                                           \
    *it = (void *)t;                                                           \
    a.value = *it;                                                             \
    a.type = typeof(t);                                                        \
  }

mkis(int, TYPE_INT);
mkis(char, TYPE_CHAR);
mkis(str, TYPE_CHAR_POINTER);
mkis(float, TYPE_CHAR_POINTER);
#endif /* ANY_H */
