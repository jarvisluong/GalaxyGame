#ifndef ISTATISTICS_HH
#define ISTATISTICS_HH

namespace Common {

class IStatistics
{
public:


    IStatistics() = default;

    virtual ~IStatistics() = default;

    virtual void addSavedShip() = 0;
    virtual unsigned getSavedShips() const = 0;
    virtual void addLostShip() = 0;
    virtual unsigned getLostShips() const = 0;

    virtual void addPoints(unsigned amount) = 0;
    virtual void reducePoints(unsigned amount) = 0;
    virtual unsigned getPoints() const = 0;

    virtual void addCredits(unsigned amount) = 0;
    virtual void reduceCredits(unsigned amount) = 0;
    virtual int getCreditBalance() const = 0;
};

}//Common

#endif // ISTATISTICS_HH
