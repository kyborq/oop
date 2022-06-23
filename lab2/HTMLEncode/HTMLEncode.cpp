#include <iostream>
#include <string>
#include <map>
#include <optional>

using namespace std;

string HtmlEncode(string const&);

int main()
{
    string htmlLine;
    while (getline(cin, htmlLine))
    {
        string encodedHtml = HtmlEncode(htmlLine);
        cout << encodedHtml << endl;
    }
}

optional<string> GetHtmlCode(char &symbol)
{
    map<char, string> replacements{
        { '\'', "&apos" },
        { '"', "&quot;" },
        { '<', "&lt;" },
        { '>', "&gt;" },
        { '&', "&amp;" }
    };

    auto iterator = replacements.find(symbol);

    if (iterator != replacements.end())
        return replacements[symbol];

    return nullopt;
}

string HtmlEncode(string const& text)
{
    string encodedText;

    for (char ch : text)
    {
        auto htmlEntity = GetHtmlCode(ch);
        if (!htmlEntity)
        {
            encodedText += ch;
        }
        else
        {
            encodedText += htmlEntity.value();
        }
    }
    return encodedText;
}
