
#if !defined(VMFDEFS) && defined(__VMDEFS_H__)
#define      VMFDEFS
typedef ByteCodeIter    BCI;
#endif

#ifndef TYPEFDEFS
#define TYPEFDEFS
typedef unsigned char  byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ul;
typedef unsigned long long ull;
#endif

#if !defined(OBJECTSFDEFS) && defined(__OBJECTS_H__)
#define      OBJECTSFDEFS
typedef DataObjectGroup DOG;
#endif
