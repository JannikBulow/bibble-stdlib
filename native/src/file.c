// Copyright 2026 Jannik Laugmand Bülow

#include <libos/file.h>

#include <BibbleInterface.h>

#include <stdbool.h>

VMReturnValue GetStdFile(os_stdfile stdfile) {
    os_file* file;
    os_result res = os_file_get_stdfile(&file, stdfile);
    if (res != OS_OK) return BIBBLE_CLITERAL(VMReturnValue){false, {.h = NULL}};
    return BIBBLE_CLITERAL(VMReturnValue){false, {.h = file}};
}

BIBBLE_EXPORT VMReturnValue BIBBLE_CALL Bibble_bibble_2internal_2file_stdin(BibbleVM* vm, BibbleInterface* interface, VMValue* args) {
    return GetStdFile(OS_STDIN);
}

BIBBLE_EXPORT VMReturnValue BIBBLE_CALL Bibble_bibble_2internal_2file_stdout(BibbleVM* vm, BibbleInterface* interface, VMValue* args) {
    return GetStdFile(OS_STDOUT);
}

BIBBLE_EXPORT VMReturnValue BIBBLE_CALL Bibble_bibble_2internal_2file_stderr(BibbleVM* vm, BibbleInterface* interface, VMValue* args) {
    return GetStdFile(OS_STDERR);
}

BIBBLE_EXPORT VMReturnValue BIBBLE_CALL Bibble_bibble_2internal_2file_open(BibbleVM* vm, BibbleInterface* interface, VMValue* args) {
    return BIBBLE_RETURN(VMInt, 0);
}

BIBBLE_EXPORT VMReturnValue BIBBLE_CALL Bibble_bibble_2internal_2file_close(BibbleVM* vm, BibbleInterface* interface, VMValue* args) {
    return BIBBLE_RETURN(VMInt, 0);
}

BIBBLE_EXPORT VMReturnValue BIBBLE_CALL Bibble_bibble_2internal_2file_write_1byte(BibbleVM* vm, BibbleInterface* interface, VMValue* args) {
    VMHandle fileHandle = args[0].h;
    VMByte b = args[1].b;

    os_file* file = fileHandle;
    os_size bytesWritten;
    os_result res = os_file_write(file, &b, sizeof(b), &bytesWritten);
    if (res != OS_OK) {
        //TODO: error
    }

    return BIBBLE_RETURN(VMULong, bytesWritten);
}

BIBBLE_EXPORT VMReturnValue BIBBLE_CALL Bibble_bibble_2internal_2file_read_1byte(BibbleVM* vm, BibbleInterface* interface, VMValue* args) {
    VMHandle fileHandle = args[0].h;

    os_file* file = fileHandle;
    VMByte b;
    os_result res = os_file_read(file, &b, sizeof(VMByte), NULL);
    if (res != OS_OK) {
        //TODO: error
    }

    return BIBBLE_RETURN(VMByte, b);
}