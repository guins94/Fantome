#include "Text.h"

void Text::RemakeTexture () {
  if(this->texture != nullptr){
    this->texture == nullptr;
  }
  this->font = Resources::GetFont(this->fontFile, this->fontSize);
  SDL_Surface* surface;
  switch (this->style) {
    case BLENDED:
      surface = TTF_RenderText_Blended(this->font, this->text.c_str(), this->color);
      this->texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), surface);
      SDL_FreeSurface(surface);
      break;
    case SHADED:
      TTF_RenderText_Shaded(this->font, this->text.c_str(), this->color, this->color);
      this->texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), surface);
      SDL_FreeSurface(surface);
      break;
    case SOLID:
      surface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->color);
      this->texture = SDL_CreateTextureFromSurface(Game::GetInstance()->GetRenderer(), surface);
      SDL_FreeSurface(surface);
      break;
    default:
      break;
    }

  SDL_QueryTexture(this->texture, nullptr, nullptr,&clipRect.h ,&clipRect.w);
  //this->height = this->height/this->frameCount;
  //SetClip(0, 0, this->Sprite::GetHeight() ,this->Sprite::GetWidth());
}

Text::Text(GameObject* associated, std::string text, TextStyle style, std::string fontFile, int fontSize, SDL_Color color) {
  this->associated = associated;
  this->text = text;
  this->style = style;
  this->fontFile = fontFile;
  this->fontSize = fontSize;
  this->color = color;
  this->texture = nullptr;
  //this->font;
  RemakeTexture ();
}

Text::~Text() {

}

void Text::Update(float dt) {

}

void Text::Render() {
  SDL_Rect dstrect;
  dstrect.h = this->associated->box.h;
  dstrect.w = this->associated->box.w;
  dstrect.x = this->associated->box.x;
  dstrect.y = this->associated->box.y;
  SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), this->texture, &clipRect, &dstrect,this->associated->angleDeg,0,SDL_FLIP_NONE);
}

bool Text::Is(std::string type) {
  return (type == "Text");
}

void Text::SetText(std::string text) {
  this->text = text;
  RemakeTexture ();
}

void Text::SetColor(SDL_Color color) {
  this->color = color;
  RemakeTexture ();
}

void Text::SetStyle(TextStyle style) {
  this->style = style;
  RemakeTexture ();
}

void Text::SetFontSize(int fontSize) {
  this->fontSize = fontSize;
  RemakeTexture ();
}

void Text::SetFontFile(std::string fontFile) {
  this->fontFile = fontFile;
  RemakeTexture ();
}
