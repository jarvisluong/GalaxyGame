#ifndef CONSTANTS_H
#define CONSTANTS_H
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
};

#endif // CONSTANTS_H
