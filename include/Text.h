#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef TEXT_HEADER
#define TEXT_HEADER

enum TextStyle {SOLID = 2, SHADED= 1, BLENDED=0};

class Text : public Component{
  private:
    std::string text;
    TextStyle style;
    std::string fontFile;
    int fontSize;
    SDL_Color color;
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Rect clipRect;
  private:
    void RemakeTexture ();
  public:
    Text(GameObject* associated, std::string text, TextStyle style, std::string fontFile, int fontSize, SDL_Color color);
  public:
    ~Text();
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is(std::string type);
  public:
    void SetText(std::string text);
  public:
    void SetColor(SDL_Color color);
  public:
    void SetStyle(TextStyle style);
  public:
    void SetFontSize(int fontSize);
  public:
    void SetFontFile(std::string fontFile);
};

#endif
