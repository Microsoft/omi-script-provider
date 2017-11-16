// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT license.
#include "shared.hpp"


#include <cstring>


void Zero_PyTypeObject (PyTypeObject* pObjOut)
{
    PyTypeObject const OBJ = {
        // Works on both Python 2 and Python 3, ob_size is the second argument
        PyVarObject_HEAD_INIT(NULL, 0)
    };
    if (NULL != pObjOut)
    {
        memcpy (pObjOut, &OBJ, sizeof (PyTypeObject));
        pObjOut->tp_name = NULL;
        pObjOut->tp_basicsize = 0;
        pObjOut->tp_itemsize = 0;
        pObjOut->tp_dealloc = NULL;
        pObjOut->tp_print = NULL;
        pObjOut->tp_getattr = NULL;
        pObjOut->tp_setattr = NULL;
        #if PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION > 4
            // Called tp_as_async in Python 3 ( > 3.4)
            pObjOut->tp_as_async = NULL;
        #elif PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION <= 4
            // Called tp_reserved in Python 3 (3 - 3.4)
            pObjOut->tp_reserved = NULL;
        #else
            // Called tp_compare in Python 2 ( < 3)
            pObjOut->tp_compare = NULL;
        #endif
        pObjOut->tp_repr = NULL;
        pObjOut->tp_as_number = NULL;
        pObjOut->tp_as_sequence = NULL;
        pObjOut->tp_as_mapping = NULL;
        pObjOut->tp_hash = NULL;
        pObjOut->tp_call = NULL;
        pObjOut->tp_str = NULL;
        pObjOut->tp_getattro = NULL;
        pObjOut->tp_setattro = NULL;
        pObjOut->tp_as_buffer = NULL;
        pObjOut->tp_flags = Py_TPFLAGS_DEFAULT;
        pObjOut->tp_doc = NULL;
        pObjOut->tp_traverse = NULL;
        pObjOut->tp_clear = NULL;
        pObjOut->tp_richcompare = NULL;
        pObjOut->tp_weaklistoffset = 0;
        pObjOut->tp_iter = NULL;
        pObjOut->tp_iternext = NULL;
        pObjOut->tp_methods = NULL;
        pObjOut->tp_members = NULL;
        pObjOut->tp_getset = NULL;
        pObjOut->tp_base = NULL;
        pObjOut->tp_dict = NULL;
        pObjOut->tp_descr_get = NULL;
        pObjOut->tp_descr_set = NULL;
        pObjOut->tp_dictoffset = 0;
        pObjOut->tp_init = NULL;
        pObjOut->tp_alloc = NULL;
        pObjOut->tp_new = NULL;
        pObjOut->tp_free = NULL;
        pObjOut->tp_is_gc = NULL;
        pObjOut->tp_bases = NULL;
        pObjOut->tp_mro = NULL;
        pObjOut->tp_cache = NULL;
        pObjOut->tp_subclasses = NULL;
        pObjOut->tp_weaklist = NULL;
        pObjOut->tp_del = NULL;
        //pObjOut->tp_version_tag;
    }
}
