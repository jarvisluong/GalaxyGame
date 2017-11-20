#ifndef UTILITIES_HH
#define UTILITIES_HH

namespace Utilities {
    /*!
     * \brief assert that the pointer is not null
     */
    template<class T>
    void assert_not_null(T* x) {
        Q_ASSERT(x != NULL);
    }
}
#endif // UTILITIES_HH
