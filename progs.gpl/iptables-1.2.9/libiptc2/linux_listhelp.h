#ifndef _LINUX_LISTHELP_H
#define _LINUX_LISTHELP_H
#include <stdlib.h>
#include <string.h>
#include "linux_list.h"

/* Header to do more comprehensive job than linux/list.h; assume list
   is first entry in structure. */

/* Return pointer to first true entry, if any, or NULL.  A macro
   required to allow inlining of cmpfn. */
#define LIST_FIND(head, cmpfn, type, args...)		\
({							\
	const struct list_head *__i = (head);		\
							\
	do {						\
		__i = __i->next;			\
		if (__i == (head)) {			\
			__i = NULL;			\
			break;				\
		}					\
	} while (!cmpfn((const type)__i , ## args));	\
	(type)__i;					\
})

#define LIST_FIND_W(head, cmpfn, type, args...)	\
({						\
	const struct list_head *__i = (head);	\
						\
	do {					\
		__i = __i->next;		\
		if (__i == (head)) {		\
			__i = NULL;		\
			break;			\
		}				\
	} while (!cmpfn((type)__i , ## args));	\
	(type)__i;				\
})

static inline int
__list_cmp_same(const void *p1, const void *p2) { return p1 == p2; }

/* Is this entry in the list? */
static inline int
list_inlist(struct list_head *head, const void *entry)
{
	return LIST_FIND(head, __list_cmp_same, void *, entry) != NULL;
}

/* Delete from list. */
#define LIST_DELETE(head, oldentry) list_del((struct list_head *)oldentry)

/* Append. */
static inline void
list_append(struct list_head *head, void *new)
{
	list_add((new), (head)->prev);
}

/* Prepend. */
static inline void
list_prepend(struct list_head *head, void *new)
{
	list_add(new, head);
}

/* Insert according to ordering function; insert before first true. */
#define LIST_INSERT(head, new, cmpfn)				\
do {								\
	struct list_head *__i;					\
	for (__i = (head)->next;				\
	     !cmpfn((new), (typeof (new))__i) && __i != (head);	\
	     __i = __i->next);					\
	list_add((struct list_head *)(new), __i->prev);		\
} while(0)

/* If the field after the list_head is a nul-terminated string, you
   can use these functions. */
static inline int __list_cmp_name(const void *i, const char *name)
{
	return strcmp(name, i+sizeof(struct list_head)) == 0;
}

/* Returns false if same name already in list, otherwise does insert. */
static inline int
list_named_insert(struct list_head *head, void *new)
{
	if (LIST_FIND(head, __list_cmp_name, void *,
		      new + sizeof(struct list_head)))
		return 0;
	list_prepend(head, new);
	return 1;
}

/* Find this named element in the list. */
#define list_named_find(head, name)			\
LIST_FIND(head, __list_cmp_name, void *, name)

#endif /*_LISTHELP_H*/
