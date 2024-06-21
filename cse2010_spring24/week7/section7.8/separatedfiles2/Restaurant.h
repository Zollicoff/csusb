#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include "Reviews.h"

class Restaurant {
   public:
      void SetName(std::string restaurantName);
      void ReadAllReviews();
      void PrintCommentsByRating() const;

   private:
      std::string name;
      Reviews reviews;
};

#endif