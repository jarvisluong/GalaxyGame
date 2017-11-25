#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "point.hh"
#include <QString>
#include <QRect>
/*!
 * \brief The Constants struct, this includes all constants and presets
 * for the game
 */
struct Constants
{
public:
    Constants();

    /*!
     * \brief restartGameCode is the exit code that is used for restart the game
     */
    static const int restartGameCode = 200;

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

    /*!
     * \brief sceneRect defines the size of the scene
     */
    static const QRect sceneRect;

    /*!
     * \brief star_image_author is the author of the star image
     */
    static const QString star_image_author;

    /*!
     * \brief playerMaxHealth is the maximum health of the player
     */
    static const int playerMaxHealth = 50;

    /*!
     * \brief initialPlayerLocation is the initial location of the player in the galaxy
     */
    static const Common::Point initialPlayerLocation;

    static const QString no_points_to_show;

    static const QString your_top_10;

    static const QString directory;

    static const QString string0;
};

#endif // CONSTANTS_H
