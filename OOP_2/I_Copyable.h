#pragma once
class I_Managable;

class I_Copyable
{
public:
	virtual void Copy(I_Copyable * object) = 0;
	virtual bool is_Equal(I_Managable * object) = 0;
};
