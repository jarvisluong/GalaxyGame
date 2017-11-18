#ifndef UTILITIES_HH
#define UTILITIES_HH
namespace Utilities {
    template<class T>
    void assert_not_null(T* x) {
        Q_ASSERT(x != NULL);
    }
}
#endif // UTILITIES_HH
