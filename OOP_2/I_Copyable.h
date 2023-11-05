#pragma once
class I_Managable;

class I_Copyable
{
public:
	virtual I_Managable * Copy() = 0;
	virtual bool is_Equal(I_Managable * object) = 0;
};
