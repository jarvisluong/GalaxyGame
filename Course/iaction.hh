#ifndef IACTION_HH
#define IACTION_HH


namespace Common {

class IAction
{
public:

    IAction() = default;
    virtual ~IAction() = default;

    virtual bool canDo() const = 0;
    virtual bool execute() = 0;
};

}

#endif // IACTION_HH
