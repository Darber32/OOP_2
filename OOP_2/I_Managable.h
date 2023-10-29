#pragma once
#include "I_Printable.h"
#include "I_Copyable.h"
#include "I_Value.h"

class I_Managable: public I_Printable, public I_Copyable, public I_Value
{
};
