#include "UICollection.h"

UICollection::UICollection() {
    this->pos = glm::vec3(0,0,0);
    this->size = glm::vec3(0,0,0);
}

void UICollection::add(UIText* text){
	amount.push_back(text);
}

void UICollection::remove(UIText* text) {
    for (int i = 0; i < amount.size(); i++) {
		if (amount[i] == text) {
			amount.erase(amount.begin() + i);
			break;
		}
	}
}

std::vector<UIText*> UICollection::AllText() {
	return amount;
}

int UICollection::TextSize(){
	return amount.size();
}