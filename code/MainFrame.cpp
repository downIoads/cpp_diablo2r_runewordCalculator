#include "MainFrame.h"
#include "Runeword.h"


// event table (must be declared in h file and defined here)
BEGIN_EVENT_TABLE (MainFrame, wxFrame)
    EVT_BUTTON(id_btn_invert, MainFrame::InvertRunes)
    EVT_BUTTON(id_btn_reset, MainFrame::ResetRunes)
    EVT_BUTTON(id_btn_sort, MainFrame::SortRunes)
    EVT_BUTTON(id_btn_calc, MainFrame::CalculateResults)
    EVT_LISTBOX(id_runeword_listbox, MainFrame::ShowRunewordStats)
END_EVENT_TABLE()


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) :
    wxFrame(NULL, -1 , title, pos, size){

    // define custom font (enables monospace on windows)
    wxFont* my_font = new wxFont(14, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_NORMAL);

    // apply custom font to runeword stats
    static_results->SetFont(*my_font);

    // panel for invert button
    wxPanel *btn_panel_invert = new wxPanel(this, wxID_ANY,
        wxPoint(20, 20), wxSize(160, 40));

    // panel for reset button
    wxPanel *btn_panel_reset = new wxPanel(this, wxID_ANY,
        wxPoint(20, 64), wxSize(160, 40));

    // panel for sort button
    wxPanel *btn_panel_sort = new wxPanel(this, wxID_ANY,
        wxPoint(20, 460), wxSize(160, 40));

    // set background color to white
    btn_panel_invert->SetBackgroundColour(*wxWHITE);
    btn_panel_reset->SetBackgroundColour(*wxWHITE);
    btn_panel_sort->SetBackgroundColour(*wxWHITE);

    // panel for calculate button
    wxPanel *btn_panel_calc = new wxPanel(this, wxID_ANY,
        wxPoint(294, 390), wxSize(200, 60));
    // set background color to white
    btn_panel_calc->SetBackgroundColour(*wxWHITE);

    // panel for rune checkboxes
    wxPanel *checkbox_panel = new wxPanel(this, wxID_ANY,
        wxPoint(25, 120), wxSize(184, 320));    // adjust value of first wxSize entry if names are cut off
    // set background color to white (or else it will be grey on windows)
    checkbox_panel->SetBackgroundColour(*wxWHITE);

    // vertical divider 1
    wxStaticLine *vertical_div_1 = new wxStaticLine(this, wxID_ANY,
        wxPoint(520, 0), wxSize(1, 440));

    // vertical divider 2
    wxStaticLine *vertical_div_2 = new wxStaticLine(this, wxID_ANY,
        wxPoint(1020, 0), wxSize(1, 440));

    // display static text (item type)
    wxStaticText *static_itemselection = new wxStaticText(this, wxID_ANY,
        "Item Type", wxPoint(294, 110), wxSize(80, 30));

    // display static text (sockets)
    wxStaticText *static_sockets = new wxStaticText(this, wxID_ANY,
        "Sockets", wxPoint(294, 210), wxSize(80, 30));

    // display static text (max level req)
    wxStaticText *static_levelreq = new wxStaticText(this, wxID_ANY,
        "Max Level Requirement", wxPoint(294, 310), wxSize(160, 30));

    // display static text (possible runewords)
    wxStaticText *static_runeword_results = new wxStaticText(this, wxID_ANY,
        "Possible runewords:", wxPoint(572, 16), wxSize(280, 20));


    choice_arr1.Add("Axes");
    choice_arr1.Add("Body Armor");
    choice_arr1.Add("Bows");        // missile weapon
    choice_arr1.Add("Claws");
    choice_arr1.Add("Clubs");
    choice_arr1.Add("Crossbows");   // missile weapon
    choice_arr1.Add("Daggers");
    choice_arr1.Add("Flails");
    choice_arr1.Add("Hammers");
    choice_arr1.Add("Helmets");
    choice_arr1.Add("Javelins");
    choice_arr1.Add("Katars");
    choice_arr1.Add("Maces");
    choice_arr1.Add("Orbs");        // doesnt count as missile AFAIK
    choice_arr1.Add("Polearms");
    choice_arr1.Add("Scepters");
    choice_arr1.Add("Shields");
    choice_arr1.Add("Spears");
    choice_arr1.Add("Staves");
    choice_arr1.Add("Swords");
    choice_arr1.Add("Wands");

    // weapon choice
    choice_1 = new wxChoice(this, wxID_ANY, wxPoint(294, 140),
    wxSize(200, 30), choice_arr1);
    choice_1->SetSelection(1);

    // socket choice
    choice_arr2.Add(wxT("2"));
    choice_arr2.Add(wxT("3"));
    choice_arr2.Add(wxT("4"));
    choice_arr2.Add(wxT("5"));
    choice_arr2.Add(wxT("6"));
    choice_2 = new wxChoice(this, wxID_ANY, wxPoint(294, 240),
    wxSize(200, 30), choice_arr2);
    choice_2->SetSelection(0);

    // max level req choice (interestingly there are no runewords with lvl 31 or 33 req)
    choice_arr3.Add(wxT("Any"));
    choice_arr3.Add(wxT("<= 13"));
    choice_arr3.Add(wxT("<= 15"));
    choice_arr3.Add(wxT("<= 17"));
    choice_arr3.Add(wxT("<= 19"));
    choice_arr3.Add(wxT("<= 21"));
    choice_arr3.Add(wxT("<= 23"));
    choice_arr3.Add(wxT("<= 25"));
    choice_arr3.Add(wxT("<= 27"));
    choice_arr3.Add(wxT("<= 29"));
    choice_arr3.Add(wxT("<= 35"));
    choice_arr3.Add(wxT("<= 37"));
    choice_arr3.Add(wxT("<= 39"));
    choice_arr3.Add(wxT("<= 41"));
    choice_arr3.Add(wxT("<= 43"));
    choice_arr3.Add(wxT("<= 45"));
    choice_arr3.Add(wxT("<= 47"));
    choice_arr3.Add(wxT("<= 49"));
    choice_arr3.Add(wxT("<= 51"));
    choice_arr3.Add(wxT("<= 53"));
    choice_arr3.Add(wxT("<= 55"));
    choice_arr3.Add(wxT("<= 57"));
    choice_arr3.Add(wxT("<= 59"));
    choice_arr3.Add(wxT("<= 61"));
    choice_arr3.Add(wxT("<= 63"));
    choice_arr3.Add(wxT("<= 65"));
    choice_arr3.Add(wxT("<= 67"));
    choice_arr3.Add(wxT("<= 69"));

    choice_3 = new wxChoice(this, wxID_ANY, wxPoint(294, 340),
    wxSize(200, 30), choice_arr3);
    choice_3->SetSelection(0);

    // widget: menubar tabs
    wxMenuBar *menuBar = new wxMenuBar;


    // LIST RUNEWORDS MENU
    wxMenu* menuRunewordList = new wxMenu();
    menuBar->Append(menuRunewordList, "&List Runewords");

    // A-C
    wxMenu* menuAC = new wxMenu();
    menuRunewordList->Append(wxID_ANY, "&A-C", menuAC);
    menuAC->Append(id_runewordlist_ancients_pledge, "&Ancient's Pledge");
    menuAC->Append(id_runewordlist_beast, "&Beast");
    menuAC->Append(id_runewordlist_black, "&Black");
    menuAC->Append(id_runewordlist_bone, "&Bone");
    menuAC->Append(id_runewordlist_bramble, "&Bramble");
    menuAC->Append(id_runewordlist_brand, "&Brand");
    menuAC->Append(id_runewordlist_breath_of_the_dying, "&Breath of the Dying");
    menuAC->Append(id_runewordlist_bulwark, "&Bulwark");
    menuAC->Append(id_runewordlist_call_to_arms, "&Call to Arms");
    menuAC->Append(id_runewordlist_chains_of_honor, "&Chains of Honor");
    menuAC->Append(id_runewordlist_crescent_moon, "&Crescent Moon");
    menuAC->Append(id_runewordlist_cure, "&Cure");

    // D-E
    wxMenu* menuDE = new wxMenu();
    menuRunewordList->Append(wxID_ANY, "&D-E", menuDE);
    menuDE->Append(id_runewordlist_death, "&Death");
    menuDE->Append(id_runewordlist_delirium, "&Delirium");
    menuDE->Append(id_runewordlist_destruction, "&Destruction");
    menuDE->Append(id_runewordlist_doom, "&Doom");
    menuDE->Append(id_runewordlist_dragon, "&Dragon");
    menuDE->Append(id_runewordlist_dream, "&Dream");
    menuDE->Append(id_runewordlist_duress, "&Duress");
    menuDE->Append(id_runewordlist_edge, "&Edge");
    menuDE->Append(id_runewordlist_enigma, "&Enigma");
    menuDE->Append(id_runewordlist_enlightenment, "&Enlightenment");
    menuDE->Append(id_runewordlist_eternity, "&Eternity");
    menuDE->Append(id_runewordlist_exile, "&Exile");

    // F-H
    wxMenu* menuFH = new wxMenu();
    menuRunewordList->Append(wxID_ANY, "&F-H", menuFH);
    menuFH->Append(id_runewordlist_faith, "&Faith");
    menuFH->Append(id_runewordlist_famine, "&Famine");
    menuFH->Append(id_runewordlist_flickering_flame, "&Flickering Flame");
    menuFH->Append(id_runewordlist_fortitude, "&Fortitude");
    menuFH->Append(id_runewordlist_fury, "&Fury");
    menuFH->Append(id_runewordlist_gloom, "&Gloom");
    menuFH->Append(id_runewordlist_grief, "&Grief");
    menuFH->Append(id_runewordlist_ground, "&Ground");
    menuFH->Append(id_runewordlist_hand_of_justice, "&Hand of Justice");
    menuFH->Append(id_runewordlist_harmony, "&Harmony");
    menuFH->Append(id_runewordlist_heart_of_the_oak, "&Heart of the Oak");
    menuFH->Append(id_runewordlist_hearth, "&Hearth");
    menuFH->Append(id_runewordlist_holy_hunder, "&Holy Thunder");
    menuFH->Append(id_runewordlist_honor, "&Honor");
    menuFH->Append(id_runewordlist_hustle, "&Hustle");

    // I-L
    wxMenu* menuIL = new wxMenu();
    menuRunewordList->Append(wxID_ANY, "&I-L", menuIL);
    menuIL->Append(id_runewordlist_ice, "&Ice");
    menuIL->Append(id_runewordlist_infinity, "&Infinity");
    menuIL->Append(id_runewordlist_insight, "&Insight");
    menuIL->Append(id_runewordlist_kings_grace, "&King's Grace");
    menuIL->Append(id_runewordlist_kingslayer, "&Kingslayer");
    menuIL->Append(id_runewordlist_last_wish, "&Last Wish");
    menuIL->Append(id_runewordlist_lawbringer, "&Lawbringer");
    menuIL->Append(id_runewordlist_leaf, "&Leaf");
    menuIL->Append(id_runewordlist_lionheart, "&Lionheart");
    menuIL->Append(id_runewordlist_lore, "&Lore");

    // M-O
    wxMenu* menuMO = new wxMenu();
    menuRunewordList->Append(wxID_ANY, "&M-O", menuMO);
    menuMO->Append(id_runewordlist_malice, "&Malice");
    menuMO->Append(id_runewordlist_melody, "&Melody");
    menuMO->Append(id_runewordlist_memory, "&Memory");
    menuMO->Append(id_runewordlist_metamorphosis, "&Metamorphosis");
    menuMO->Append(id_runewordlist_mist, "&Mist");
    menuMO->Append(id_runewordlist_mosaic, "&Mosaic");
    menuMO->Append(id_runewordlist_myth, "&Myth");
    menuMO->Append(id_runewordlist_nadir, "&Nadir");
    menuMO->Append(id_runewordlist_oath, "&Oath");
    menuMO->Append(id_runewordlist_obedience, "&Obedience");
    menuMO->Append(id_runewordlist_obsession, "&Obesession");

    // P-R
    wxMenu* menuPR = new wxMenu();
    menuRunewordList->Append(wxID_ANY, "&P-R", menuPR);
    menuPR->Append(id_runewordlist_passion, "&Passion");
    menuPR->Append(id_runewordlist_pattern, "&Pattern");
    menuPR->Append(id_runewordlist_peace, "&Peace");
    menuPR->Append(id_runewordlist_phoenix, "&Phoenix");
    menuPR->Append(id_runewordlist_plague, "&Plague");
    menuPR->Append(id_runewordlist_pride, "&Pride");
    menuPR->Append(id_runewordlist_principle, "&Principle");
    menuPR->Append(id_runewordlist_prudence, "&Prudence");
    menuPR->Append(id_runewordlist_radiance, "&Radiance");
    menuPR->Append(id_runewordlist_rain, "&Rain");
    menuPR->Append(id_runewordlist_rhyme, "&Rhyme");
    menuPR->Append(id_runewordlist_rift, "&Rift");

    // S-T
    wxMenu* menuST = new wxMenu();
    menuRunewordList->Append(wxID_ANY, "&S-T", menuST);
    menuST->Append(id_runewordlist_sanctuary, "&Sanctuary");
    menuST->Append(id_runewordlist_silence, "&Silence");
    menuST->Append(id_runewordlist_smoke, "&Smoke");
    menuST->Append(id_runewordlist_spirit, "&Spirit");
    menuST->Append(id_runewordlist_splendor, "&Splendor");
    menuST->Append(id_runewordlist_stealth, "&Stealth");
    menuST->Append(id_runewordlist_steel, "&Steel");
    menuST->Append(id_runewordlist_stone, "&Stone");
    menuST->Append(id_runewordlist_strength, "&Strength");
    menuST->Append(id_runewordlist_temper, "&Temper");
    menuST->Append(id_runewordlist_treachery, "&Treachery");

    // U-Z
    wxMenu* menuUZ = new wxMenu();
    menuRunewordList->Append(wxID_ANY, "&U-Z", menuUZ);
    menuUZ->Append(id_runewordlist_unbending_will, "&Unbending Will");
    menuUZ->Append(id_runewordlist_venom, "&Venom");
    menuUZ->Append(id_runewordlist_voice_of_reason, "&Voice of Reason");
    menuUZ->Append(id_runewordlist_wealth, "&Wealth");
    menuUZ->Append(id_runewordlist_white, "&White");
    menuUZ->Append(id_runewordlist_wind, "&Wind");
    menuUZ->Append(id_runewordlist_wisdom, "&Wisdom");
    menuUZ->Append(id_runewordlist_wrath, "&Wrath");
    menuUZ->Append(id_runewordlist_zephyr, "&Zephyr");


    // BREAKPOINTS MENU
    wxMenu *menuBreakpoints = new wxMenu();
    menuBar->Append(menuBreakpoints, "&Breakpoints");

    // amazon submenu
    wxMenu *menuAmazon = new wxMenu();
    menuBreakpoints->Append(wxID_ANY, "&Amazon", menuAmazon);
    menuAmazon->Append(id_breakpoints_amazon_ibs, "&Increased Blocking Speed");
    menuAmazon->Append(id_breakpoints_amazon_fcr, "&Faster Cast Rate");
    menuAmazon->Append(id_breakpoints_amazon_fhr, "&Faster Hit Recovery");

    // assassin submenu
    wxMenu *menuAssassin = new wxMenu();
    menuBreakpoints->Append(wxID_ANY, "&Assassin", menuAssassin);
    menuAssassin->Append(id_breakpoints_assassin_ibs, "&Increased Blocking Speed");
    menuAssassin->Append(id_breakpoints_assassin_fcr, "&Faster Cast Rate");
    menuAssassin->Append(id_breakpoints_assassin_fhr, "&Faster Hit Recovery");

    // barbarian submenu
    wxMenu *menuBarbarian = new wxMenu();
    menuBreakpoints->Append(wxID_ANY, "&Barbarian", menuBarbarian);
    menuBarbarian->Append(id_breakpoints_barbarian_ibs, "&Increased Blocking Speed");
    menuBarbarian->Append(id_breakpoints_barbarian_fcr, "&Faster Cast Rate");
    menuBarbarian->Append(id_breakpoints_barbarian_fhr, "&Faster Hit Recovery");

    // druid submenu
    wxMenu *menuDruid = new wxMenu();
    menuBreakpoints->Append(wxID_ANY, "&Druid", menuDruid);
    menuDruid->Append(id_breakpoints_druid_ibs, "&Increased Blocking Speed");
    menuDruid->Append(id_breakpoints_druid_fcr, "&Faster Cast Rate");
    menuDruid->Append(id_breakpoints_druid_fhr, "&Faster Hit Recovery");

    // necromancer submenu
    wxMenu *menuNecromancer = new wxMenu();
    menuBreakpoints->Append(wxID_ANY, "&Necromancer", menuNecromancer);
    menuNecromancer->Append(id_breakpoints_necromancer_ibs, "&Increased Blocking Speed");
    menuNecromancer->Append(id_breakpoints_necromancer_fcr, "&Faster Cast Rate");
    menuNecromancer->Append(id_breakpoints_necromancer_fhr, "&Faster Hit Recovery");

    // paladin submenu
    wxMenu *menuPaladin = new wxMenu();
    menuBreakpoints->Append(wxID_ANY, "&Paladin", menuPaladin);
    menuPaladin->Append(id_breakpoints_paladin_ibs, "&Increased Blocking Speed");
    menuPaladin->Append(id_breakpoints_paladin_fcr, "&Faster Cast Rate");
    menuPaladin->Append(id_breakpoints_paladin_fhr, "&Faster Hit Recovery");

    // sorceress submenu
    wxMenu *menuSorceress = new wxMenu();
    menuBreakpoints->Append(wxID_ANY, "&Sorceress", menuSorceress);
    menuSorceress->Append(id_breakpoints_sorceress_ibs, "&Increased Blocking Speed");
    menuSorceress->Append(id_breakpoints_sorceress_fcr, "&Faster Cast Rate");
    menuSorceress->Append(id_breakpoints_sorceress_fhr, "&Faster Hit Recovery");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    cb_el = new wxCheckBox(checkbox_panel, id_cb_el, "El", wxPoint(0, 0));
    cb_el->SetValue(true);
    wxString el_tooltip = "El Rune:\n\n\
Weapon\t\t\t+50 to Attack Rating\n\
\t\t\t+1 to Light Radius\n\n\
Shield\t\t\t+15 Defense\n\
\t\t\t+1 to Light Radius\n\n\
Armor\t\t\t+15 Defense\n\
\t\t\t+1 to Light Radius\n\n\
Cube\n\
Create this rune\t\tNot possible\n\
Upgrade this rune\t\t3 El = Eld";
    cb_el->SetToolTip(el_tooltip);


    cb_eld = new wxCheckBox(checkbox_panel, id_cb_eld, "Eld", wxPoint(60, 0));
    cb_eld->SetValue(true);
    wxString eld_tooltip = "Eld Rune:\n\n\
Weapon\t\t\t+75% Damage To Undead\n\
\t\t\t+50 Atk Rating Vs Undead\n\n\
Shield\t\t\t+7% Chance of Blocking\n\n\
Armor\t\t\t15% Slower Stamina Drain\n\n\
Cube\n\
Create this rune\t\t3 El = Eld\n\
Upgrade this rune\t\t3 Eld = Tir";
    cb_eld->SetToolTip(eld_tooltip);

    cb_tir = new wxCheckBox(checkbox_panel, id_cb_tir, "Tir", wxPoint(120, 0));
    cb_tir->SetValue(true);
    wxString tir_tooltip = "Tir Rune:\n\n\
Weapon\t\t\t+2 To Mana After Each Kill\n\n\
Shield\t\t\t+2 To Mana After Each Kill\n\n\
Armor\t\t\t+2 To Mana After Each Kill\n\n\
Cube\n\
Create this rune\t\t3 Eld = Tir\n\
Upgrade this rune\t\t3 Tir = Nef";
    cb_tir->SetToolTip(tir_tooltip);

    cb_nef = new wxCheckBox(checkbox_panel, id_cb_nef, "Nef", wxPoint(0, 30));
    cb_nef->SetValue(true);
    wxString nef_tooltip = "Nef Rune:\n\n\
Weapon\t\t\tKnockback\n\n\
Shield\t\t\t+30 Defense vs. Missile\n\n\
Armor\t\t\t+30 Defense vs. Missile\n\n\
Cube\n\
Create this rune\t\t3 Tir = Nef\n\
Upgrade this rune\t\t3 Nef = Eth";
    cb_nef->SetToolTip(nef_tooltip);

    cb_eth = new wxCheckBox(checkbox_panel, id_cb_eth, "Eth", wxPoint(60, 30));
    cb_eth->SetValue(true);
    wxString eth_tooltip = "Eth Rune:\n\n\
Weapon\t\t\t-25% To Target Defense\n\n\
Shield\t\t\tRegenerate Mana 15%\n\n\
Armor\t\t\tRegenerate Mana 15%\n\n\
Cube\n\
Create this rune\t\t3 Nef = Eth\n\
Upgrade this rune\t\t3 Eth = Ith";
    cb_eth->SetToolTip(eth_tooltip);

    cb_ith = new wxCheckBox(checkbox_panel, id_cb_ith, "Ith", wxPoint(120, 30));
    cb_ith->SetValue(true);
    wxString ith_tooltip = "Ith Rune:\n\n\
Weapo\t\t\t+9 To Maximum Dmg\n\n\
Shield\t\t\t15% Dmg Taken to Mana\n\n\
Armor\t\t\t15% Dmg Taken to Mana\n\n\
Cube\n\
Create this rune\t\t3 Eth = Ith\n\
Upgrade this rune\t\t3 Ith = Tal";
    cb_ith->SetToolTip(ith_tooltip);

    cb_tal = new wxCheckBox(checkbox_panel, id_cb_tal, "Tal", wxPoint(0, 60));
    cb_tal->SetValue(true);
    wxString tal_tooltip = "Tal Rune:\n\n\
Weapon\t\t\t+75 Poison Dmg (5 Sec)\n\n\
Shield\t\t\tPoison Resist 30%\n\n\
Armor\t\t\tPoison Resist 30%\n\n\
Cube\n\
Create this rune\t\t3 Ith = Tal\n\
Upgrade this rune\t\t3 Tal = Ral";
    cb_tal->SetToolTip(tal_tooltip);

    cb_ral = new wxCheckBox(checkbox_panel, id_cb_ral, "Ral", wxPoint(60, 60));
    cb_ral->SetValue(true);
    wxString ral_tooltip = "Ral Rune:\n\n\
Weapon\t\t\tAdds 5-30 Fire Damage\n\n\
Shield\t\t\tFire Resist 30%\n\n\
Armor\t\t\tFire Resist 30%\n\n\
Cube\n\
Create this rune\t\t3 Tal = Ral\n\
Upgrade this rune\t\t3 Ral = Ort";
    cb_ral->SetToolTip(ral_tooltip);

    cb_ort = new wxCheckBox(checkbox_panel, id_cb_ort, "Ort", wxPoint(120, 60));
    cb_ort->SetValue(true);
    wxString ort_tooltip = "Ort Rune:\n\n\
Weapon\t\t\tAdds 1-50 Lightn. Dmg\n\n\
Shield\t\t\tLightning Resist 30%\n\n\
Armor\t\t\tLightning Resist 30%\n\n\
Cube\n\
Create this rune\t\t3 Ral = Ort\n\
Upgrade this rune\t\t3 Ort = Thul";
    cb_ort->SetToolTip(ort_tooltip);

    cb_thul = new wxCheckBox(checkbox_panel, id_cb_thul, "Thul",
                wxPoint(0, 90));
    cb_thul->SetValue(true);
    wxString thul_tooltip = "Thul Rune:\n\n\
Weapon\t\tAdds 3-14 Cold Damage\n\n\
Shield\t\tCold Resist 35%\n\n\
Armor\t\tCold Resist 30%\n\n\
Cube\n\
Create this rune\t3 Ort = Thul\n\
Upgrade this rune\t3 Thul + Chipped Topaz = Amn";
    cb_thul->SetToolTip(thul_tooltip);

    cb_amn = new wxCheckBox(checkbox_panel, id_cb_amn, "Amn", wxPoint(60, 90));
    cb_amn->SetValue(true);
    wxString amn_tooltip = "Amn Rune:\n\n\
Weapon\t\t7% Life Stolen Per Hit\n\n\
Shield\t\tAttacker Takes Dmg of 14\n\n\
Armor\t\tAttacker Takes Dmg of 14\n\n\
Cube\n\
Create this rune\t3 Thul + Chipped Topaz = Amn\n\
Upgrade this rune\t3 Amn + Chipped Amethyst = Sol";
    cb_amn->SetToolTip(amn_tooltip);

    cb_sol = new wxCheckBox(checkbox_panel, id_cb_sol, "Sol", wxPoint(120, 90));
    cb_sol->SetValue(true);
    wxString sol_tooltip = "Sol Rune:\n\n\
Weapon\t\t+9 To Minimum Damage\n\n\
Shield\t\tDamage Reduced By 7\n\n\
Armor\t\tDamage Reduced By 7\n\n\
Cube\n\
Create this rune\t3 Amn + Chipped Amethyst = Sol\n\
Upgrade this rune\t3 Sol + Chipped Sapphire = Shael";
    cb_sol->SetToolTip(sol_tooltip);

    cb_shael = new wxCheckBox(checkbox_panel, id_cb_shael, "Shael",
                wxPoint(0, 120));
    cb_shael->SetValue(true);
    wxString shael_tooltip = "Shael Rune:\n\n\
Weapon\t\t20% Increased Attack Speed\n\n\
Shield\t\t20% Faster Block Rate\n\n\
Armor\t\t20% Faster Hit Recovery\n\n\
Cube\n\
Create this rune\t3 Sol + Chipped Sapphire = Shael\n\
Upgrade this rune\t3 Shael + Chipped Ruby = Dol";
    cb_shael->SetToolTip(shael_tooltip);

    cb_dol = new wxCheckBox(checkbox_panel, id_cb_dol, "Dol", wxPoint(60, 120));
    cb_dol->SetValue(true);
    wxString dol_tooltip = "Dol Rune:\n\n\
Weapon\t\tHit Causes Monster To Flee +25%\n\n\
Shield\t\tReplenish Life +7\n\n\
Armor\t\tReplenish Life +7\n\n\
Cube\n\
Create this rune\t3 Shael + Chipped Ruby = Dol\n\
Upgrade this rune\t3 Dol + Chipped Emerald = Hel";
    cb_dol->SetToolTip(dol_tooltip);

    cb_hel = new wxCheckBox(checkbox_panel, id_cb_hel, "Hel",
                wxPoint(120, 120));
    cb_hel->SetValue(true);
    wxString hel_tooltip = "Hel Rune:\n\n\
Weapon\t\tRequirements -20%\n\n\
Shield\t\tRequirements -15%\n\n\
Armor\t\tRequirements -15%\n\n\
Cube\n\
Create this rune\t3 Dol + Chipped Emerald = Hel\n\
Upgrade this rune\t3 Hel + Chipped Diamond = Io";
    cb_hel->SetToolTip(hel_tooltip);

    cb_io = new wxCheckBox(checkbox_panel, id_cb_io, "Io", wxPoint(0, 150));
    cb_io->SetValue(true);
    wxString io_tooltip = "Io Rune:\n\n\
Weapon\t\t+10 To Vitality\n\n\
Shield\t\t+10 To Vitality\n\n\
Armor\t\t+10 To Vitality\n\n\
Cube\n\
Create this rune\t3 Hel + Chipped Diamond = Io\n\
Upgrade this rune\t3 Io + Flawed Topaz = Lum";
    cb_io->SetToolTip(io_tooltip);

    cb_lum = new wxCheckBox(checkbox_panel, id_cb_lum, "Lum", wxPoint(60, 150));
    cb_lum->SetValue(true);
    wxString lum_tooltip = "Lum Rune:\n\n\
Weapon\t\t+10 To Energy\n\n\
Shield\t\t+10 To Energy\n\n\
Armor\t\t+10 To Energy\n\n\
Cube\n\
Create this rune\t3 Io + Flawed Topaz = Lum\n\
Upgrade this rune\t3 Lum + Flawed Amethyst = Ko";
    cb_lum->SetToolTip(lum_tooltip);

    cb_ko = new wxCheckBox(checkbox_panel, id_cb_ko, "Ko", wxPoint(120, 150));
    cb_ko->SetValue(true);
    wxString ko_tooltip = "Ko Rune:\n\n\
Weapon\t\t+10 To Dexterity\n\n\
Shield\t\t+10 To Dexterity\n\n\
Armor\t\t+10 To Dexterity\n\n\
Cube\n\
Create this rune\t3 Lum + Flawed Amethyst = Ko\n\
Upgrade this rune\t3 Ko + Flawed Sapphire = Fal";
    cb_ko->SetToolTip(ko_tooltip);

    cb_fal = new wxCheckBox(checkbox_panel, id_cb_fal, "Fal", wxPoint(0, 180));
    cb_fal->SetValue(true);
    wxString fal_tooltip = "Fal Rune:\n\n\
Weapon\t\t+10 To Strength\n\n\
Shield\t\t+10 To Strength\n\n\
Armor\t\t+10 To Strength\n\n\
Cube\n\
Create this rune\t3 Ko + Flawed Sapphire = Fal\n\
Upgrade this rune\t3 Fal + Flawed Ruby = Lem";
    cb_fal->SetToolTip(fal_tooltip);

    cb_lem = new wxCheckBox(checkbox_panel, id_cb_lem, "Lem", wxPoint(60, 180));
    cb_lem->SetValue(true);
    wxString lem_tooltip = "Lem Rune:\n\n\
Weapon\t\t75% Extra Gold From Monsters\n\n\
Shield\t\t50% Extra Gold From Monsters\n\n\
Armor\t\t50% Extra Gold From Monsters\n\n\
Cube\n\
Create this rune\t3 Fal + Flawed Ruby = Lem\n\
Upgrade this rune\t3 Lem + Flawed Emerald = Pul";
    cb_lem->SetToolTip(lem_tooltip);

    cb_pul = new wxCheckBox(checkbox_panel, id_cb_pul, "Pul",
            wxPoint(120, 180));
    cb_pul->SetValue(true);
    wxString pul_tooltip = "Pul Rune:\n\n\
Weapon\t\t+75% Damage To Demons\n\
\t\t+100 Attack Rating vs. Demons\n\n\
Shield\t\t+30% Enhanced Defense\n\n\
Armor\t\t+30% Enhanced Defense\n\n\
Cube\n\
Create this rune\t3 Lem + Flawed Emerald = Pul\n\
Upgrade this rune\t2 Pul + Flawed Diamond = Um";
    cb_pul->SetToolTip(pul_tooltip);

    cb_um = new wxCheckBox(checkbox_panel, id_cb_um, "Um", wxPoint(0, 210));
    cb_um->SetValue(true);
    wxString um_tooltip = "Um Rune:\n\n\
Weapon\t\t+25% Chance of Open Wounds\n\n\
Shield\t\tAll Resistances +22\n\n\
Armor\t\tAll Resistances +15\n\n\
Cube\n\
Create this rune\t2 Pul + Flawed Diamond = Um\n\
Upgrade this rune\t2 Um + Topaz = Mal";
    cb_um->SetToolTip(um_tooltip);

    cb_mal = new wxCheckBox(checkbox_panel, id_cb_mal, "Mal", wxPoint(60, 210));
    cb_mal->SetValue(true);
    wxString mal_tooltip = "Mal Rune:\n\n\
Weapon\t\tPrevent Monster Heal\n\n\
Shield\t\tMagic Damage Reduced By 7\n\n\
Armor\t\tMagic Damage Reduced By 7\n\n\
Cube\n\
Create this rune\t2 Um + Topaz = Mal\n\
Upgrade this rune\t2 Mal + Amethyst = Ist";
    cb_mal->SetToolTip(mal_tooltip);

    cb_ist = new wxCheckBox(checkbox_panel, id_cb_ist, "Ist",
                wxPoint(120, 210));
    cb_ist->SetValue(true);
    wxString ist_tooltip = "Ist Rune:\n\n\
Weapon\t\t30% Magic Find\n\n\
Shield\t\t25% Magic Find\n\n\
Armor\t\t25% Magic Find\n\n\
Cube\n\
Create this rune\t2 Mal + Amethyst = Ist\n\
Upgrade this rune\t2 Ist + Sapphire = Gul";
    cb_ist->SetToolTip(ist_tooltip);

    cb_gul = new wxCheckBox(checkbox_panel, id_cb_gul, "Gul", wxPoint(0, 240));
    cb_gul->SetValue(true);
    wxString gul_tooltip = "Gul Rune:\n\n\
Weapon\t\t20% Bonus To Attack Rating\n\n\
Shield\t\t5% To Maximum Poison Resist\n\n\
Armor\t\t5% To Maximum Poison Resist\n\n\
Cube\n\
Create this rune\t2 Ist + Sapphire = Gul\n\
Upgrade this rune\t2 Gul + Ruby = Vex";
    cb_gul->SetToolTip(gul_tooltip);

    cb_vex = new wxCheckBox(checkbox_panel, id_cb_vex, "Vex", wxPoint(60, 240));
    cb_vex->SetValue(true);
    wxString vex_tooltip = "Vex Rune:\n\n\
Weapon\t\t7% Mana Stolen Per Hit\n\n\
Shield\t\t5% To Maximum Fire Resist\n\n\
Armor\t\t5% To Maximum Fire Resist\n\n\
Cube\n\
Create this rune\t2 Gul + Ruby = Vex\n\
Upgrade this rune\t2 Vex + Emerald = Ohm";
    cb_vex->SetToolTip(vex_tooltip);

    cb_ohm = new wxCheckBox(checkbox_panel, id_cb_ohm, "Ohm",
                wxPoint(120, 240));
    cb_ohm->SetValue(true);
    wxString ohm_tooltip = "Ohm Rune:\n\n\
Weapon\t\t+50% Enhanced Damage\n\n\
Shield\t\t5% To Maximum Cold Resist\n\n\
Armor\t\t5% To Maximum Cold Resist\n\n\
Cube\n\
Create this rune\t2 Vex + Emerald = Ohm\n\
Upgrade this rune\t2 Ohm + Diamond = Lo";
    cb_ohm->SetToolTip(ohm_tooltip);

    cb_lo = new wxCheckBox(checkbox_panel, id_cb_lo, "Lo", wxPoint(0, 270));
    cb_lo->SetValue(true);
    wxString lo_tooltip = "Lo Rune:\n\n\
Weapon\t\t+20% Deadly Strike\n\n\
Shield\t\t5% To Max Lightning Resist\n\n\
Armor\t\t5% To Max Lightning Resist\n\n\
Cube\n\
Create this rune\t2 Ohm + Diamond = Lo\n\
Upgrade this rune\t2 Lo + Flawless Topaz = Sur";
    cb_lo->SetToolTip(lo_tooltip);

    cb_sur = new wxCheckBox(checkbox_panel, id_cb_sur, "Sur", wxPoint(60, 270));
    cb_sur->SetValue(true);
    wxString sur_tooltip = "Sur Rune:\n\n\
Weapon\t\tHit Blinds Target\n\n\
Shield\t\t+50 To Mana\n\n\
Armor\t\t5% To Maximum Mana\n\n\
Cube\n\
Create this rune\t2 Lo + Flawless Topaz = Sur\n\
Upgrade this rune\t2 Sur + Flawless Amethyst = Ber";
    cb_sur->SetToolTip(sur_tooltip);

    cb_ber = new wxCheckBox(checkbox_panel, id_cb_ber, "Ber",
                wxPoint(120, 270));
    cb_ber->SetValue(true);
    wxString ber_tooltip = "Ber Rune:\n\n\
Weapon\t\t+20% Crushing Blow Chance\n\n\
Shield\t\tDamage Reduced by 8%\n\n\
Armor\t\tDamage Reduced by 8%\n\n\
Cube\n\
Create this rune\t2 Sur + Flawless Amethyst = Ber\n\
Upgrade this rune\t2 Ber + Flawless Sapphire = Jah";
    cb_ber->SetToolTip(ber_tooltip);

    cb_jah = new wxCheckBox(checkbox_panel, id_cb_jah, "Jah", wxPoint(0, 300));
    cb_jah->SetValue(true);
    wxString jah_tooltip = "Jah Rune:\n\n\
Weapon\t\tIgnore Target's Defense\n\n\
Shield\t\t+50 Life\n\n\
Armor\t\tIncrease Maximum Life 5%\n\n\
Cube\n\
Create this rune\t2 Ber + Flawless Sapphire = Jah\n\
Upgrade this rune\t2 Jah + Flawless Ruby = Cham";
    cb_jah->SetToolTip(jah_tooltip);

    cb_cham = new wxCheckBox(checkbox_panel, id_cb_cham, "Cham",
                wxPoint(60, 300));
    cb_cham->SetValue(true);
    wxString cham_tooltip = "Cham Rune:\n\n\
Weapon\t\tFreeze Target +3\n\n\
Shield\t\tCannot Be Frozen\n\n\
Armor\t\tCannot Be Frozen\n\n\
Cube\n\
Create this rune\t2 Jah + Flawless Ruby = Cham\n\
Upgrade this rune\t2 Cham + Flawless Emerald = Zod";
    cb_cham->SetToolTip(cham_tooltip);

    cb_zod = new wxCheckBox(checkbox_panel, id_cb_zod, "Zod",
                wxPoint(120, 300));
    cb_zod->SetValue(true);
    wxString zod_tooltip = "Zod Rune:\n\n\
Weapon\t\tIndestructible\n\n\
Shield\t\tIndestructible\n\n\
Armor\t\tIndestructible\n\n\
Cube\n\
Create this rune\t2 Cham + Flawless Emerald = Zod\n\
Upgrade this rune\tNot possible";
    cb_zod->SetToolTip(zod_tooltip);

    set_cb_pointers = {cb_el, cb_eld, cb_tir, cb_nef,
    cb_eth, cb_ith, cb_tal, cb_ral, cb_ort, cb_thul, cb_amn, cb_sol, cb_shael,
    cb_dol, cb_hel, cb_io, cb_lum, cb_ko, cb_fal, cb_lem, cb_pul, cb_um, cb_mal,
    cb_ist, cb_gul, cb_vex, cb_ohm, cb_lo, cb_sur,
    cb_ber, cb_jah, cb_cham, cb_zod};


    // widget: button invert
    wxButton *btn_invert = new wxButton(btn_panel_invert, id_btn_invert,
        "Invert", wxPoint(0, 0), wxSize(160, 40));
    btn_invert->SetToolTip(wxT("Invert Rune Selection"));

    // widget: button reset
    wxButton *btn_reset = new wxButton(btn_panel_reset, id_btn_reset,
        "Reset", wxPoint(0, 0), wxSize(160, 40));
    btn_reset->SetToolTip(wxT("Reset Rune Selection"));

    // widget: button sort (has been pre-defined in h file so that it is accessible everywhere)
    btn_sort = new wxButton(btn_panel_sort, id_btn_sort,
        "Sort A-Z", wxPoint(0, 0), wxSize(160, 40));
    btn_sort->SetToolTip(wxT("Changes Rune Sorting Order (Alphabetical vs Rarity)"));


    // widget: button calc
    wxButton *btn_calc = new wxButton(btn_panel_calc, id_btn_calc,
        "Calculate Runewords", wxPoint(0, 0), wxSize(200, 50));
    btn_calc->SetToolTip(wxT("Calculates All Possible Runewords"));

    // add custom message at the bottom
    CreateStatusBar();
    SetStatusText("");

    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

    // breakpoints, assign menubar clicks to function calls

    // amazon
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsAmazonIBS, this, id_breakpoints_amazon_ibs);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsAmazonFCR, this, id_breakpoints_amazon_fcr);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsAmazonFHR, this, id_breakpoints_amazon_fhr);

    // assassin
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsAssassinIBS, this, id_breakpoints_assassin_ibs);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsAssassinFCR, this, id_breakpoints_assassin_fcr);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsAssassinFHR, this, id_breakpoints_assassin_fhr);


    // barbarian
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsBarbarianIBS, this, id_breakpoints_barbarian_ibs);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsBarbarianFCR, this, id_breakpoints_barbarian_fcr);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsBarbarianFHR, this, id_breakpoints_barbarian_fhr);


    // druid
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsDruidIBS, this, id_breakpoints_druid_ibs);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsDruidFCR, this, id_breakpoints_druid_fcr);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsDruidFHR, this, id_breakpoints_druid_fhr);

    // necromancer
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsNecromancerIBS, this, id_breakpoints_necromancer_ibs);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsNecromancerFCR, this, id_breakpoints_necromancer_fcr);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsNecromancerFHR, this, id_breakpoints_necromancer_fhr);

    // paladin
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsPaladinIBS, this, id_breakpoints_paladin_ibs);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsPaladinFCR, this, id_breakpoints_paladin_fcr);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsPaladinFHR, this, id_breakpoints_paladin_fhr);

    // sorceress
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsSorceressIBS, this, id_breakpoints_sorceress_ibs);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsSorceressFCR, this, id_breakpoints_sorceress_fcr);
    Bind(wxEVT_MENU, &MainFrame::OnBreakpointsSorceressFHR, this, id_breakpoints_sorceress_fhr);

    // BIND list runewords
    for (int ez  = 60; ez < 152; ez++){ // id's start at 60 and are naturally increased by 1 as long as enum isnt changed this works
        Bind(wxEVT_MENU, &MainFrame::OnRunewordListSelectionClick, this, ez);
    }

}


void MainFrame::OnExit(wxCommandEvent &event){
    Close(true);
}



void MainFrame::OnAbout(wxCommandEvent &event){
    wxMessageBox("Hey, if you find any bugs or false information please add or message:\nscar10 on Discord.\n\nYou can say thanks by donating non-ladder runes or you can tell me\nwhich features you would like to see!\n\
\nProgram Version: 2.7",
                 "About", wxOK | wxICON_INFORMATION); // this line is the title of the info box that opens
}

// the following spaces allign correctly on windows. sadly on linux you manually have to change the spaces so that it aligns or you define custom message boxes
void MainFrame::OnBreakpointsAmazonIBS(wxCommandEvent& event) {
    wxMessageBox("Amazon\n\n\
Increased Blocking Speed                Frames\n\n\
1H Swinging Weapon:\n\
0                                                           17\n\
4                                                           16\n\
6                                                           15\n\
11                                                         14\n\
15                                                         13\n\
23                                                         12\n\
29                                                         11\n\
40                                                         10\n\
56                                                          9\n\
80                                                          8\n\
120                                                        7\n\
200                                                        6\n\
480                                                        5\n\
\n\
Other Weapons:\n\
0                                                            5\n\
13                                                          4\n\
32                                                          3\n\
86                                                          2\n\
600                                                        1\n\
", "Amazon IBS Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsAmazonFCR(wxCommandEvent& event) {
    wxMessageBox("Amazon\n\n\
Faster Cast Rate                Frames\n\n\
0                                          19\n\
7                                          18\n\
14                                        17\n\
22                                        16\n\
32                                        15\n\
48                                        14\n\
68                                        13\n\
99                                        12\n\
152                                      11\n\
", "Amazon FCR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsAmazonFHR(wxCommandEvent& event) {
    wxMessageBox("Amazon\n\n\
Faster Hit Recovery                Frames\n\n\
0                                                11\n\
6                                                10\n\
13                                               9\n\
20                                               8\n\
32                                               7\n\
52                                               6\n\
86                                               5\n\
174                                             4\n\
600                                             3\n\
", "Amazon FHR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsAssassinIBS(wxCommandEvent& event) {
    wxMessageBox("Assassin\n\n\
Increased Blocking Speed                Frames\n\n\
0                                                           5\n\
13                                                         4\n\
32                                                         3\n\
86                                                         2\n\
600                                                       1\n\
", "Assassin IBS Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsAssassinFCR(wxCommandEvent& event) {
    wxMessageBox("Assassin\n\n\
Faster Cast Rate                Frames\n\n\
0                                          16\n\
8                                          15\n\
16                                        14\n\
27                                        13\n\
42                                        12\n\
65                                        11\n\
102                                      10\n\
174                                       9\n\
", "Assassin FCR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsAssassinFHR(wxCommandEvent& event) {
    wxMessageBox("Assassin\n\n\
Faster Hit Recovery                Frames\n\n\
0                                                9\n\
7                                                8\n\
15                                              7\n\
27                                              6\n\
48                                              5\n\
86                                              4\n\
200                                            3\n\
", "Assassin FHR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsBarbarianIBS(wxCommandEvent& event) {
    wxMessageBox("Barbarian\n\n\
Increased Blocking Speed                Frames\n\n\
0                                                           7\n\
9                                                           6\n\
20                                                         5\n\
42                                                         4\n\
86                                                         3\n\
280                                                       2\n\
", "Barbarian IBS Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsBarbarianFCR(wxCommandEvent& event) {
    wxMessageBox("Barbarian\n\n\
Faster Cast Rate                Frames\n\n\
0                                          13\n\
9                                          12\n\
20                                        11\n\
37                                        10\n\
63                                         9\n\
105                                       8\n\
200                                       7\n\
", "Barbarian FCR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsBarbarianFHR(wxCommandEvent& event) {
    wxMessageBox("Barbarian\n\n\
Faster Hit Recovery                Frames\n\n\
0                                                9\n\
7                                                8\n\
15                                              7\n\
27                                              6\n\
48                                              5\n\
86                                              4\n\
200                                            3\n\
", "Barbarian FHR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsDruidIBS(wxCommandEvent& event) {
    wxMessageBox("Druid\n\n\
Increased Blocking Speed                Frames\n\n\
Human Form\n\
0                                                           11\n\
6                                                           10\n\
13                                                          9\n\
20                                                          8\n\
32                                                          7\n\
52                                                          6\n\
86                                                          5\n\
174                                                        4\n\
600                                                        3\n\n\
Bear Form\n\
0                                                           12\n\
5                                                           11\n\
10                                                         10\n\
16                                                          9\n\
27                                                          8\n\
40                                                          7\n\
65                                                          6\n\
109                                                        5\n\
223                                                        4\n\n\
Wolf Form\n\
0                                                            9\n\
7                                                            8\n\
15                                                          7\n\
27                                                          6\n\
48                                                          5\n\
86                                                          4\n\
200                                                        3\n\
", "Druid IBS Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsDruidFCR(wxCommandEvent& event) {
    wxMessageBox("Druid\n\n\
Faster Cast Rate                Frames\n\n\
Human Form\n\
0                                          18\n\
4                                          17\n\
10                                        16\n\
19                                        15\n\
30                                        14\n\
46                                        13\n\
68                                        12\n\
99                                        11\n\
163                                      10\n\n\
Bear Form\n\
0                                          16\n\
7                                          15\n\
15                                        14\n\
26                                        13\n\
40                                        12\n\
63                                        11\n\
99                                        10\n\
163                                       9\n\n\
Wolf Form\n\
0                                          16\n\
6                                          15\n\
14                                        14\n\
26                                        13\n\
40                                        12\n\
60                                        11\n\
95                                        10\n\
157                                       9\n\
", "Druid FCR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsDruidFHR(wxCommandEvent& event) {
    wxMessageBox("Druid\n\n\
Faster Hit Recovery                Frames\n\n\
Human Form\n\
1H Swinging Weapon\n\
0                                                14\n\
3                                                13\n\
7                                                12\n\
13                                              11\n\
19                                              10\n\
29                                               9\n\
42                                               8\n\
63                                               7\n\
99                                               6\n\
174                                             5\n\
456                                             4\n\n\
Human Form\n\
Other Weapons\n\
0                                                13\n\
5                                                12\n\
10                                              11\n\
16                                              10\n\
26                                               9\n\
39                                               8\n\
56                                               7\n\
86                                               6\n\
152                                             5\n\
377                                             4\n\n\
Bear Form\n\
0                                                13\n\
5                                                12\n\
10                                              11\n\
16                                              10\n\
24                                               9\n\
37                                               8\n\
54                                               7\n\
86                                               6\n\
152                                             5\n\
360                                             4\n\n\
Wolf Form\n\
0                                                 7\n\
9                                                 6\n\
20                                               5\n\
42                                               4\n\
86                                               3\n\
280                                             2\n\
", "Druid FHR Breakpoints", wxOK | wxICON_INFORMATION);
}


void MainFrame::OnBreakpointsNecromancerIBS(wxCommandEvent& event) {
    wxMessageBox("Necromancer\n\n\
Increased Blocking Speed                Frames\n\n\
0                                                           11\n\
6                                                           10\n\
13                                                          9\n\
20                                                          8\n\
32                                                          7\n\
52                                                          6\n\
86                                                          5\n\
174                                                        4\n\
600                                                        3\n\n\
", "Necromancer IBS Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsNecromancerFCR(wxCommandEvent& event) {
    wxMessageBox("Necromancer\n\n\
Faster Cast Rate                Frames\n\n\
Human\n\
0                                          15\n\
9                                          14\n\
18                                        13\n\
30                                        12\n\
48                                        11\n\
75                                        10\n\
125                                       9\n\n\
Vampire\n\
0                                          23\n\
6                                          22\n\
11                                        21\n\
18                                        20\n\
24                                        19\n\
35                                        18\n\
48                                        17\n\
65                                        16\n\
86                                        15\n\
120                                      14\n\
180                                      13\n\
", "Necromancer FCR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsNecromancerFHR(wxCommandEvent& event) {
    wxMessageBox("Necromancer\n\n\
Faster Hit Recovery                Frames\n\n\
Human\n\
0                                                13\n\
5                                                12\n\
10                                              11\n\
16                                              10\n\
26                                               9\n\
39                                               8\n\
56                                               7\n\
86                                               6\n\
152                                             5\n\
377                                             4\n\n\
Vampire\n\
0                                                15\n\
2                                                14\n\
6                                                13\n\
10                                              12\n\
16                                              11\n\
24                                              10\n\
34                                               9\n\
48                                               8\n\
72                                               7\n\
117                                             6\n\
208                                             5\n\
", "Necromancer FHR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsPaladinIBS(wxCommandEvent& event) {
    wxMessageBox("Paladin\n\n\
Increased Blocking Speed                Frames\n\n\
Without Holy Shield:\n\
0                                                           5\n\
13                                                         4\n\
32                                                         3\n\
86                                                         2\n\
600                                                       1\n\
\n\
With Holy Shield:\n\
0                                                           2\n\
86                                                         1\n\
", "Paladin IBS Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsPaladinFCR(wxCommandEvent& event) {
    wxMessageBox("Paladin\n\n\
Faster Cast Rate                Frames\n\n\
0                                          15\n\
9                                          14\n\
18                                        13\n\
30                                        12\n\
48                                        11\n\
75                                        10\n\
125                                       9\n\
", "Paladin FCR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsPaladinFHR(wxCommandEvent& event) {
    wxMessageBox("Paladin\n\n\
Faster Hit Recovery                Frames\n\n\
Spears and Staves\n\
0                                                13\n\
3                                                12\n\
7                                                11\n\
13                                              10\n\
20                                               9\n\
32                                               8\n\
48                                               7\n\
75                                               6\n\
129                                             5\n\
280                                             4\n\n\
Other Weapons\n\
0                                                 9\n\
7                                                 8\n\
15                                               7\n\
27                                               6\n\
48                                               5\n\
86                                               4\n\
200                                             3\n\
", "Paladin FHR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsSorceressIBS(wxCommandEvent& event) {
    wxMessageBox("Sorceress\n\n\
Increased Blocking Speed                Frames\n\n\
0                                                           9\n\
7                                                           8\n\
15                                                         7\n\
27                                                         6\n\
48                                                         5\n\
86                                                         4\n\
200                                                       3\n\
", "Sorceress IBS Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsSorceressFCR(wxCommandEvent& event) {
    wxMessageBox("Sorceress\n\n\
Faster Cast Rate                Frames\n\n\
(Chain) Lightning\n\
0                                          19\n\
7                                          18\n\
15                                        17\n\
23                                        16\n\
35                                        15\n\
52                                        14\n\
78                                        13\n\
117                                      12\n\
194                                      11\n\n\
Other Spells\n\
0                                          13\n\
9                                          12\n\
20                                        11\n\
37                                        10\n\
63                                         9\n\
105                                       8\n\
200                                       7\n\
", "Sorceress FCR Breakpoints", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnBreakpointsSorceressFHR(wxCommandEvent& event) {
    wxMessageBox("Sorceress\n\n\
Faster Hit Recovery                Frames\n\n\
0                                                15\n\
5                                                14\n\
9                                                13\n\
14                                              12\n\
20                                              11\n\
30                                              10\n\
42                                               9\n\
60                                               8\n\
86                                               7\n\
142                                             6\n\
280                                             5\n\
", "Sorceress FHR Breakpoints", wxOK | wxICON_INFORMATION);
}


void MainFrame::OnRunewordListSelectionClick(wxCommandEvent &event){

    int selection_id = event.GetId();

    string runeword_text = "a";

    // id 60 must be "ancients pledge" (this value is forced in enum "id_enum" defined in MainFrame.hh)
    if (selection_id == 60){
        runeword_text = GetRunewordText("Ancient's Pledge");
    }
    else if (selection_id == 61){
        runeword_text = GetRunewordText("Beast");
    }
    else if (selection_id == 62){
        runeword_text = GetRunewordText("Black");
    }
    else if (selection_id == 63){
        runeword_text = GetRunewordText("Bone");
    }
    else if (selection_id == 64){
        runeword_text = GetRunewordText("Bramble");
    }
    else if (selection_id == 65){
        runeword_text = GetRunewordText("Brand");
    }
    else if (selection_id == 66){
        runeword_text = GetRunewordText("Breath of the Dying");
    }
    else if (selection_id == 67){
        runeword_text = GetRunewordText("Bulwark");
    }
    else if (selection_id == 68){
        runeword_text = GetRunewordText("Call to Arms");
    }
    else if (selection_id == 69){
        runeword_text = GetRunewordText("Chains of Honor");
    }
    else if (selection_id == 70){
        runeword_text = GetRunewordText("Crescent Moon");
    }
    else if (selection_id == 71){
        runeword_text = GetRunewordText("Cure");
    }
    else if (selection_id == 72){
        runeword_text = GetRunewordText("Death");
    }
    else if (selection_id == 73){
        runeword_text = GetRunewordText("Delirium");
    }
    else if (selection_id == 74){
        runeword_text = GetRunewordText("Destruction");
    }
    else if (selection_id == 75){
        runeword_text = GetRunewordText("Doom");
    }
    else if (selection_id == 76){
        runeword_text = GetRunewordText("Dragon");
    }
    else if (selection_id == 77){
        runeword_text = GetRunewordText("Dream");
    }
    else if (selection_id == 78){
        runeword_text = GetRunewordText("Duress");
    }
    else if (selection_id == 79){
        runeword_text = GetRunewordText("Edge");
    }
    else if (selection_id == 80){
        runeword_text = GetRunewordText("Enigma");
    }
    else if (selection_id == 81){
        runeword_text = GetRunewordText("Enlightenment");
    }
    else if (selection_id == 82){
        runeword_text = GetRunewordText("Eternity");
    }
    else if (selection_id == 83){
        runeword_text = GetRunewordText("Exile");
    }
    else if (selection_id == 84){
        runeword_text = GetRunewordText("Faith");
    }
    else if (selection_id == 85){
        runeword_text = GetRunewordText("Famine");
    }
    else if (selection_id == 86){
        runeword_text = GetRunewordText("Flickering Flame");
    }
    else if (selection_id == 87){
        runeword_text = GetRunewordText("Fortitude");
    }
    else if (selection_id == 88){
        runeword_text = GetRunewordText("Fury");
    }
    else if (selection_id == 89){
        runeword_text = GetRunewordText("Gloom");
    }
    else if (selection_id == 90){
        runeword_text = GetRunewordText("Grief");
    }
    else if (selection_id == 91){
        runeword_text = GetRunewordText("Ground");
    }
    else if (selection_id == 92){
        runeword_text = GetRunewordText("Hand of Justice");
    }
    else if (selection_id == 93){
        runeword_text = GetRunewordText("Harmony");
    }
    else if (selection_id == 94){
        runeword_text = GetRunewordText("Heart of the Oak");
    }
    else if (selection_id == 95){
        runeword_text = GetRunewordText("Hearth");
    }
    else if (selection_id == 96){
        runeword_text = GetRunewordText("Holy Thunder");
    }
    else if (selection_id == 97){
        runeword_text = GetRunewordText("Honor");
    }
    else if (selection_id == 98){
        runeword_text = GetRunewordText("Hustle");
    }
    else if (selection_id == 99){
        runeword_text = GetRunewordText("Ice");
    }
    else if (selection_id == 100){
        runeword_text = GetRunewordText("Infinity");
    }
    else if (selection_id == 101){
        runeword_text = GetRunewordText("Insight");
    }
    else if (selection_id == 102){
        runeword_text = GetRunewordText("King's Grace");
    }
    else if (selection_id == 103){
        runeword_text = GetRunewordText("Kingslayer");
    }
    else if (selection_id == 104){
        runeword_text = GetRunewordText("Last Wish");
    }
    else if (selection_id == 105){
        runeword_text = GetRunewordText("Lawbringer");
    }
    else if (selection_id == 106){
        runeword_text = GetRunewordText("Leaf");
    }
    else if (selection_id == 107){
        runeword_text = GetRunewordText("Lionheart");
    }
    else if (selection_id == 108){
        runeword_text = GetRunewordText("Lore");
    }
    else if (selection_id == 109){
        runeword_text = GetRunewordText("Malice");
    }
    else if (selection_id == 110){
        runeword_text = GetRunewordText("Melody");
    }
    else if (selection_id == 111){
        runeword_text = GetRunewordText("Memory");
    }
    else if (selection_id == 112){
        runeword_text = GetRunewordText("Metamorphosis");
    }
    else if (selection_id == 113){
        runeword_text = GetRunewordText("Mist");
    }
    else if (selection_id == 114){
        runeword_text = GetRunewordText("Mosaic");
    }
    else if (selection_id == 115){
        runeword_text = GetRunewordText("Myth");
    }
    else if (selection_id == 116){
        runeword_text = GetRunewordText("Nadir");
    }
    else if (selection_id == 117){
        runeword_text = GetRunewordText("Oath");
    }
    else if (selection_id == 118){
        runeword_text = GetRunewordText("Obedience");
    }
    else if (selection_id == 119){
        runeword_text = GetRunewordText("Obsession");
    }
    else if (selection_id == 120){
        runeword_text = GetRunewordText("Passion");
    }
    else if (selection_id == 121){
        runeword_text = GetRunewordText("Pattern");
    }
    else if (selection_id == 122){
        runeword_text = GetRunewordText("Peace");
    }
    else if (selection_id == 123){
        runeword_text = GetRunewordText("Phoenix");
    }
    else if (selection_id == 124){
        runeword_text = GetRunewordText("Plague");
    }
    else if (selection_id == 125){
        runeword_text = GetRunewordText("Pride");
    }
    else if (selection_id == 126){
        runeword_text = GetRunewordText("Principle");
    }
    else if (selection_id == 127){
        runeword_text = GetRunewordText("Prudence");
    }
    else if (selection_id == 128){
        runeword_text = GetRunewordText("Radiance");
    }
    else if (selection_id == 129){
        runeword_text = GetRunewordText("Rain");
    }
    else if (selection_id == 130){
        runeword_text = GetRunewordText("Rhyme");
    }
    else if (selection_id == 131){
        runeword_text = GetRunewordText("Rift");
    }
    else if (selection_id == 132){
        runeword_text = GetRunewordText("Sanctuary");
    }
    else if (selection_id == 133){
        runeword_text = GetRunewordText("Silence");
    }
    else if (selection_id == 134){
        runeword_text = GetRunewordText("Smoke");
    }
    else if (selection_id == 135){
        runeword_text = GetRunewordText("Spirit");
    }
    else if (selection_id == 136){
        runeword_text = GetRunewordText("Splendor");
    }
    else if (selection_id == 137){
        runeword_text = GetRunewordText("Stealth");
    }
    else if (selection_id == 138){
        runeword_text = GetRunewordText("Steel");
    }
    else if (selection_id == 139){
        runeword_text = GetRunewordText("Stone");
    }
    else if (selection_id == 140){
        runeword_text = GetRunewordText("Strength");
    }
    else if (selection_id == 141){
        runeword_text = GetRunewordText("Temper");
    }
    else if (selection_id == 142){
        runeword_text = GetRunewordText("Treachery");
    }
    else if (selection_id == 143){
        runeword_text = GetRunewordText("Unbending Will");
    }
    else if (selection_id == 144){
        runeword_text = GetRunewordText("Venom");
    }
    else if (selection_id == 145){
        runeword_text = GetRunewordText("Voice of Reason");
    }
    else if (selection_id == 146){
        runeword_text = GetRunewordText("Wealth");
    }
    else if (selection_id == 147){
        runeword_text = GetRunewordText("White");
    }
    else if (selection_id == 148){
        runeword_text = GetRunewordText("Wind");
    }
    else if (selection_id == 149){
        runeword_text = GetRunewordText("Wisdom");
    }
    else if (selection_id == 150){
        runeword_text = GetRunewordText("Wrath");
    }
    else if (selection_id == 151){
        runeword_text = GetRunewordText("Zephyr");
    }


    wxMessageBox(runeword_text, "Runeword Description", wxOK | wxICON_INFORMATION);


}


string MainFrame::GetRunewordText(string a){

    string final_text;

    for (Runeword r: runewords){
        if (r.name == a) {
            final_text = r.name + "\n\n" + r.runeword_stats + "\nRune Formula: " + r.runeword + "\nCompatible With: ";

            // list the compatible items (but there should be no semicolon after the last item)
            int compatible_items_amt = r.items.size();
            int counter_temp = 1;
            for (string s: r.items){
                if (counter_temp < compatible_items_amt){
                    final_text += s + ", ";
                }
                else {
                    final_text += s;
                }

                counter_temp += 1;
            }
            // dont care about the other runewords so lets stop searching
            break;
        }

    }

    return final_text;
}


void MainFrame::InvertRunes(wxCommandEvent &event){
    // invert all rune checkboxes
    for (wxCheckBox *cb: set_cb_pointers){
        if (cb->IsChecked()){
            cb->SetValue(false);
        }
        else {
            cb->SetValue(true);
        }

    }

}

void MainFrame::ResetRunes(wxCommandEvent &event){
    // check all rune checkboxes
    for (wxCheckBox *cb: set_cb_pointers){
        if (!(cb->IsChecked())){
            cb->SetValue(true);
        }
    }

}

void MainFrame::SortRunes(wxCommandEvent &event){
    // toggle sorting order between A-Z and by rarity
    if (btn_sort->GetLabelText() == "Sort A-Z"){
        for (wxCheckBox *cb: set_cb_pointers){
            if (cb->GetLabelText() == "Amn"){
                cb->Move(0, 0);
                
            }
            else if (cb->GetLabelText() == "Ber"){
                cb->Move(60, 0);
            }
            else if (cb->GetLabelText() == "Cham"){
                cb->Move(120, 0);
            }
            else if (cb->GetLabelText() == "Dol"){
                cb->Move(0, 30);
            }
            else if (cb->GetLabelText() == "El"){
                cb->Move(60, 30);
            }
            else if (cb->GetLabelText() == "Eld"){
                cb->Move(120, 30);
            }
            else if (cb->GetLabelText() == "Eth"){
                cb->Move(0, 60);
            }
            else if (cb->GetLabelText() == "Fal"){
                cb->Move(60, 60);
            }
            else if (cb->GetLabelText() == "Gul"){
                cb->Move(120, 60);
            }
            else if (cb->GetLabelText() == "Hel"){
                cb->Move(0, 90);
            }
            else if (cb->GetLabelText() == "Io"){
                cb->Move(60, 90);
            }
            else if (cb->GetLabelText() == "Ist"){
                cb->Move(120, 90);
            }
            else if (cb->GetLabelText() == "Ith"){
                cb->Move(0, 120);
            }
            else if (cb->GetLabelText() == "Jah"){
                cb->Move(60, 120);
            }
            else if (cb->GetLabelText() == "Ko"){
                cb->Move(120, 120);
            }
            else if (cb->GetLabelText() == "Lem"){
                cb->Move(0, 150);
            }
            else if (cb->GetLabelText() == "Lo"){
                cb->Move(60, 150);
            }
            else if (cb->GetLabelText() == "Lum"){
                cb->Move(120, 150);
            }
            else if (cb->GetLabelText() == "Mal"){
                cb->Move(0, 180);
            }
            else if (cb->GetLabelText() == "Nef"){
                cb->Move(60, 180);
            }
            else if (cb->GetLabelText() == "Ohm"){
                cb->Move(120, 180);
            }
            else if (cb->GetLabelText() == "Ort"){
                cb->Move(0, 210);
            }
            else if (cb->GetLabelText() == "Pul"){
                cb->Move(60, 210);
            }
            else if (cb->GetLabelText() == "Ral"){
                cb->Move(120, 210);
            }
            else if (cb->GetLabelText() == "Shael"){
                cb->Move(0, 240);
            }
            else if (cb->GetLabelText() == "Sol"){
                cb->Move(60, 240);
            }
            else if (cb->GetLabelText() == "Sur"){
                cb->Move(120, 240);
            }
            else if (cb->GetLabelText() == "Tal"){
                cb->Move(0, 270);
            }
            else if (cb->GetLabelText() == "Thul"){
                cb->Move(60, 270);
            }
            else if (cb->GetLabelText() == "Tir"){
                cb->Move(120, 270);
            }
            else if (cb->GetLabelText() == "Um"){
                cb->Move(0, 300);
            }
            else if (cb->GetLabelText() == "Vex"){
                cb->Move(60, 300);
            }
            else if (cb->GetLabelText() == "Zod"){
                cb->Move(120, 300);
            }

            cb->Refresh();   // required on windows otherwise text bugged until mouse is moved over it
        }
        
        btn_sort->SetLabelText("Sort By Rarity");

    }

    else if (btn_sort->GetLabelText() == "Sort By Rarity"){
        for (wxCheckBox *cb: set_cb_pointers){
            if (cb->GetLabelText() == "El"){
                cb->Move(0, 0);
            }
            else if (cb->GetLabelText() == "Eld"){
                cb->Move(60, 0);
            }
            else if (cb->GetLabelText() == "Tir"){
                cb->Move(120, 0);
            }
            else if (cb->GetLabelText() == "Nef"){
                cb->Move(0, 30);
            }
            else if (cb->GetLabelText() == "Eth"){
                cb->Move(60, 30);
            }
            else if (cb->GetLabelText() == "Ith"){
                cb->Move(120, 30);
            }
            else if (cb->GetLabelText() == "Tal"){
                cb->Move(0, 60);
            }
            else if (cb->GetLabelText() == "Ral"){
                cb->Move(60, 60);
            }
            else if (cb->GetLabelText() == "Ort"){
                cb->Move(120, 60);
            }
            else if (cb->GetLabelText() == "Thul"){
                cb->Move(0, 90);
            }
            else if (cb->GetLabelText() == "Amn"){
                cb->Move(60, 90);
            }
            else if (cb->GetLabelText() == "Sol"){
                cb->Move(120, 90);
            }
            else if (cb->GetLabelText() == "Shael"){
                cb->Move(0, 120);
            }
            else if (cb->GetLabelText() == "Dol"){
                cb->Move(60, 120);
            }
            else if (cb->GetLabelText() == "Hel"){
                cb->Move(120, 120);
            }
            else if (cb->GetLabelText() == "Io"){
                cb->Move(0, 150);
            }
            else if (cb->GetLabelText() == "Lum"){
                cb->Move(60, 150);
            }
            else if (cb->GetLabelText() == "Ko"){
                cb->Move(120, 150);
            }
            else if (cb->GetLabelText() == "Fal"){
                cb->Move(0, 180);
            }
            else if (cb->GetLabelText() == "Lem"){
                cb->Move(60, 180);
            }
            else if (cb->GetLabelText() == "Pul"){
                cb->Move(120, 180);
            }
            else if (cb->GetLabelText() == "Um"){
                cb->Move(0, 210);
            }
            else if (cb->GetLabelText() == "Mal"){
                cb->Move(60, 210);
            }
            else if (cb->GetLabelText() == "Ist"){
                cb->Move(120, 210);
            }
            else if (cb->GetLabelText() == "Gul"){
                cb->Move(0, 240);
            }
            else if (cb->GetLabelText() == "Vex"){
                cb->Move(60, 240);
            }
            else if (cb->GetLabelText() == "Ohm"){
                cb->Move(120, 240);
            }
            else if (cb->GetLabelText() == "Lo"){
                cb->Move(0, 270);
            }
            else if (cb->GetLabelText() == "Sur"){
                cb->Move(60, 270);
            }
            else if (cb->GetLabelText() == "Ber"){
                cb->Move(120, 270);
            }
            else if (cb->GetLabelText() == "Jah"){
                cb->Move(0, 300);
            }
            else if (cb->GetLabelText() == "Cham"){
                cb->Move(60, 300);
            }
            else if (cb->GetLabelText() == "Zod"){
                cb->Move(120, 300);
            }

            cb->Refresh();   // required on windows otherwise text bugged until mouse is moved over it
        }

        btn_sort->SetLabelText("Sort A-Z");

    }

}


void MainFrame::ShowRunewordStats(wxCommandEvent &event){
    // get label of current selection to choose correct runeword stats
    int cur_sel = result_listbox->GetSelection();
    wxString cur_sel_label = result_listbox->GetString(cur_sel);

    // fix crash error when 'no possible runewords' string is selected
    if (cur_sel_label == wxT("No possible runewords.")) {
        return;
    }

    string temp5;

    // e.g. given Phoenix ("VexVexLoJah") extract VexVexLoJah to idenitify runeword
    string str = cur_sel_label.ToStdString();
    unsigned first = str.find("(");
    unsigned last = str.find(")");
    string temp4 = str.substr (first, last-first);
    // remove the first two and the last character
    temp4.erase(0, 2);
    temp4.erase(temp4.size() - 1);

    // go through all runewords and determine which runeword's stats are to be shown
    for (Runeword r: runewords){
        if (r.runeword == temp4){
            temp5 = r.name + "\n\n" + r.runeword_stats;
            break;
        }
    }
    // convert std::string to wxString
    wxString runeword_stats_text(temp5);

    static_results->SetLabel(runeword_stats_text);
}


void MainFrame::DeleteResultCheckboxContents(){

    while (result_listbox->GetCount() > 0){
        // remove item with index 0
        result_listbox->Delete(0);
    }

}


void MainFrame::ClearResultCheckboxSelections(){
    wxArrayInt selections;
    int count = result_listbox->GetSelections(selections);

    for (int i=0; i<count; ++i){
      result_listbox->Deselect(selections[i]);
    }
}


void MainFrame::CalculateResults(wxCommandEvent &event){
    // first clear previous results
    MainFrame::DeleteResultCheckboxContents();

    // then clear runeword description box
    static_results->SetLabel(wxT(""));

    set<wxString> user_runes;
    for (wxCheckBox *cb: set_cb_pointers){
        if (cb->IsChecked()){
            user_runes.insert(cb->GetLabel());
        }
    }

    // now we have a set that contains all currently selected runes as strings


    wxString item_sel = choice_1->GetString((choice_1->GetSelection()));            // get chosen item type

    wxString temp2 = choice_2->GetString((choice_2->GetSelection()));               // get chosen socket amount and cast to int
    int user_sck = wxAtoi(temp2);

    wxString max_level_selection = choice_3->GetString((choice_3->GetSelection())); // get chosen max level


    // now calculate possible runewords
    vector<Runeword> results_final = actual_calc(user_runes, item_sel,
                                                    user_sck, max_level_selection);

    // and show them
    if (results_final.size() == 0){
        result_listbox->Append(wxT("No possible runewords."));
    }
    else{
        wxString rune_item;
        for (Runeword v: results_final){
            rune_item = v.name + " (\"" + v.runeword + "\")";
            result_listbox->Append(rune_item);
        }

    }

}


