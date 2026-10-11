// Copyright 2026 Jannik Laugmand Bülow

#include <BibbleInterface.h>

#include <stdio.h>

BIBBLE_EXPORT VMReturnValue BIBBLE_CALL Bibble_bibble_2Test_PrintInt(BibbleVM* vm, BibbleInterface* interface, VMValue* args) {
    VMInt x = args[0].i;
    printf("%d\n", x);
    return BIBBLE_RETURN(VMInt, 0);
}