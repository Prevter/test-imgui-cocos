#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>

using namespace geode::prelude;

// Keep the original example code to make sure it still works
#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto myButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this, menu_selector(MyMenuLayer::onMyButton)
        );

        auto menu = this->getChildByID("bottom-menu");
        menu->addChild(myButton);

        myButton->setID("my-button"_spr);
        menu->updateLayout();

        return true;
    }

    void onMyButton(CCObject*) {
        FLAlertLayer::create("Geode", "Hello from my custom mod!", "OK")->show();
    }
};

// Load the ImGuiCocos library and use it
$execute {
    ImGuiCocos::get().setup([] {
        
    }).draw([] {
        ImGui::Begin("My awesome window");
        ImGui::Button("Awesome button");
        ImGui::End();
    });
}
