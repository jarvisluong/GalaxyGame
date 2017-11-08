#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QString>

/*!
 * \brief The Constants struct, this includes all constants and presets
 * for the game
 */
struct Constants
{
public:
    Constants();

    /*!
     * \brief gameName is the name of the game. It will also be used as
     * the window title.
     */
    static const QString gameName;

    /*!
     * \brief version is the version of the game
     */
    static const QString version;

    /*!
     * \brief author is the authors of the game
     */
    static const QString author;
};

#endif // CONSTANTS_H
