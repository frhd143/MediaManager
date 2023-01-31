#include <string>
using namespace std;
#ifndef MEDIA_H
#define MEDIA_H
class Media {     
    protected:
        string m_title;
    public:
        Media() {};
        Media(const string& title);
        virtual ~Media() {};
        const string& getTitle() const;
        virtual string prettyPrint() const = 0;
        bool operator==(const Media& other) const;
        bool operator!=(const Media& other) const;
};
#endif // MEDIA_F