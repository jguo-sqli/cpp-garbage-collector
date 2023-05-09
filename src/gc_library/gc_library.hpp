#include <iostream>
#include <memory>

#define STACK_MAX 1024
#define INIT_OBJ_NUM_MAX 8

typedef enum { OBJ_INT, OBJ_PAIR } ObjectType;

typedef struct sObject
{
  ObjectType type;
  unsigned char marked;
  /* the next object in the linked list of heap allocated objects. */
  std::unique_ptr<struct sObject> next;

  union {
    /* OBJ_INT*/
    int value;

    /* OBJ_PAIR*/
    struct
    {
      std::unique_ptr<struct sObject> head;
      std::unique_ptr<struct sObject> tail;
    };
  };
} Object;

typedef struct
{
  std::unique_ptr<Object> stack[STACK_MAX];
  int stack_size;

  /* The first object in the linked list of all objects on the heap. */
  std::unique_ptr<Object> first_object;

  /* The total number of currently allocated objects. */
  int num_objects;

  /* The number of objects required to trigger a GC. */
  int max_objects;

} VirtualMachine;
