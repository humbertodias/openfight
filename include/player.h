#ifndef _player_h
#define _player_h

#include <algorithm>
#include <string>
#include <typeinfo>
#include <sstream>
#include <iostream>
#include <map>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <SDL/SDL_opengl.h>
#include "objectManager.h"
#include "graphicsCore.h"
#include "collision.h"
#include "actions.h"
#include "animation.h"


class Player
{
   private:
      GLfloat x_pos;
      GLfloat y_pos;
      GLfloat alpha;
      GLfloat scale;

      GLfloat y_initial;
      GLfloat x_initial;
      GLfloat alpha_initial;
      GLfloat scale_initial;

      std::string type;
      bool inverted;
      bool is_hurt;
      int  index;

      std::string current_state;
      std::string previous_state;

      std::map<std::string, std::map<std::string, std::string> > states;
      std::map<std::string, std::string> next_state;
      ObjectManager<Animation> *animation_manager;

      Player *opponent;
      ObjectManager<Player> *objects;

      void setCurrentState(std::string state);
      void checkCollisions(GLfloat action_x_vel);

   public:
      Player();
      Player(const Player &p);
      ~Player();

      std::map<std::string, bool> state;

      bool operator< (const Player& p) const;
      GLfloat getXpos();
      void moveXpos(GLfloat value);
      bool isInverted();
      bool isHurt();
      Collision *getOffense();
      Collision *getDefense();

      void initialize(std::string file_name, bool player_one, GLfloat x_pos, GLfloat y_pos);
      void setOpponent(Player *opponent);
      bool updateState(std::string command);
      bool updateState(std::string command, bool from_opponent);
      bool update();
      void doAction(const std::type_info& type);
      void move(GLfloat x, GLfloat y);
      void setLocation(GLfloat x, GLfloat y);
      void createObject(std::string object);
      void copyObject(std::string object, GLfloat x, GLfloat y, int index);
      void draw();
};


#endif
