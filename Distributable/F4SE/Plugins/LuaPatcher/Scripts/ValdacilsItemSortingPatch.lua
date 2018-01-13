-- ValdacilsItemSortingPatch.lua

VIS = {}

VIS.ALCH = {}
VIS.ALCH.Aid = {
    -- Addictol
    [ 0x000459C5 ] = true,
    -- Antibiotics
    [ 0x000008AB ] = true,
    [ 0x00249F2C ] = true,
    -- Curie's Healthpak
    [ 0x0019C0D9 ] = true,
    -- Glowing Blood Pack
    [ 0x00058AB4 ] = true,
    -- Herbal Anodyne
    [ 0x00249F8E ] = true,
    -- Herbal Antimicrobial
    [ 0x00249F8F ] = true,
    -- Herbal Stimulant
    [ 0x00249F8D ] = true,
    -- Rad-X
    [ 0x00024057 ] = true,
    -- RadAway
    [ 0x00023742 ] = true,
    -- Skeeto Spit
    [ 0x00058ABC ] = true,
    -- Stimpak
    [ 0x00023736 ] = true,
    -- X-111 Compound
    [ 0x0007238F ] = true,
}
VIS.ALCH.Prewar = {
    -- Blamco Brand Mac and Cheese
    [ 0x0002FBE4 ] = true,
    [ 0x000E3768 ] = true,
    -- Bubblegum
    [ 0x000330F6 ] = true,
    -- Canned Dog Food
    [ 0x000BEA58 ] = true,
    -- Cotton Candy Bites
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x02689A) ] = true,
    -- Cram
    [ 0x000330EE ] = true,
    -- Dandy Boy Apples
    [ 0x0002FBF7 ] = true,
    -- Fancy Lads Snack Cakes
    [ 0x000330B4 ] = true,
    [ 0x000E3778 ] = true,
    -- Funnel Cake
    [ 0x0602689B ] = true,
    -- Gum Drops
    [ 0x000330FC ] = true,
    -- Happy Birthday Sweet Roll
    [ 0x001D33D2 ] = true,
    -- InstaMash
    [ 0x000366B9 ] = true,
    -- Moldy Food
    [ 0x001A6397 ] = true,
    -- Pork n' Beans
    [ 0x000330F0 ] = true,
    -- Potato Crisps
    [ 0x000330F1 ] = true,
    -- Potted Meat
    [ 0x0016D8C8 ] = true,
    -- Preserved InstaMash
    [ 0x000E377A ] = true,
    -- Salisbury Steak
    [ 0x000366BA ] = true,
    [ 0x000E3780 ] = true,
    -- Sugar Bombs
    [ 0x000330F2 ] = true,
    [ 0x000E3782 ] = true,
    -- Sweet Roll
    [ 0x000366BE ] = true,
    -- Yum Yum Deviled Eggs
    [ 0x000366BD ] = true,
}
VIS.ALCH.Quest = {
    -- Brainwave Interference
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04BDAE) ] = true,
    -- Ghoul Meat
    [ 0x00024075 ] = true,
    -- Hypnotic Pheromones
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04BDB6) ] = true,
    -- Molerat Disease
    [ 0x00249690 ] = true,
    -- Mysterious Serum
    [ 0x000EC4F7 ] = true,
    -- Pristine Deathclaw Egg
    [ 0x00134C68 ] = true,
    -- Subliminal Suggestions
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04BDB7) ] = true,
    -- Theta Radiation
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04BDB8) ] = true,
    -- Vault 81 Cure
    [ 0x00055F10 ] = true,
}
VIS.ALCH.Device = {
    [ Game.GetFormFromFile("WestTekTacticalOptics.esp", 0x00A834) ] = true,
}

VIS.AMMO = {}
VIS.AMMO.Fuel = {
    -- Flamer Fuel
    [ 0x000CAC78 ] = true,
    -- Fusion Core
    [ 0x00075FE4 ] = true,
}

VIS.BOOK = {}
VIS.BOOK.Quest = {
    -- Note
    [ 0x0002FD6D ] = true,
    -- Power Armor Frame
    [ 0x001F4265 ] = true,
    [ 0x00218C4D ] = true,
    [ 0x00218C51 ] = true,
    [ 0x0021A6A4 ] = true,
    -- Silver Shroud Photo
    [ 0x0018AC1E ] = true,
    -- Vault 88 Chemical Research
    [ Game.GetFormFromFile("DLCworkshop03.esm", 0x004BC6) ] = true,
    -- Vault-Tec Prototypes
    [ Game.GetFormFromFile("DLCworkshop03.esm", 0x0053DA) ] = true,
    -- Wellingham's Recipe
    [ 0x001A71E8 ] = true,
}
VIS.BOOK.Password = {
    -- Barney's Password
    [ 0x002301D1 ] = true,
    -- Bergman's Password
    [ 0x0015B0BA ] = true,
    -- Federal Ration Stockpile Password
    [ 0x000EC357 ] = true,
    -- Four Leaf Fishpacking Security Password
    [ 0x000F9338 ] = true,
    -- Greentech Terminal Password
    [ 0x0006D0E2 ] = true,
    -- Storage Password
    [ 0x000E56FF ] = true,
}

VIS.KEYM = {}
VIS.KEYM.Passcard = {
    -- Arcjet Lab Password
    [ 0x0011C4EB ] = true,
    -- Arcjet Project Manager's Password
    [ 0x001F3CA8 ] = true,
    -- Atomatoys Developer's Password: Marlene
    [ 0x00118B0D ] = true,
    -- Atomatoys Security Office Password
    [ 0x00117F98 ] = true,
    -- Blood Clinic Password
    [ 0x0010C476 ] = true,
    -- Campbell's Safe Password
    [ 0x0008C3FE ] = true,
    -- Drinkin' Buddy Password
    [ 0x0019900E ] = true,
    -- Eager Ernie's Password
    [ 0x0013CB54 ] = true,
    -- Emogene Cabot's Password
    [ 0x001E97B9 ] = true,
    -- Federal Ration Stockpile Password
    [ 0x001A458E ] = true,
    -- First Mate's Password
    [ 0x001B48AC ] = true,
    -- Fort Hagen Armory Password
    [ 0x00099D3E ] = true,
    -- Four Leaf Security Password
    [ 0x001793DD ] = true,
    -- Fred Allen's Password
    [ 0x001C3AF8 ] = true,
    -- Galleria DMS Override Password
    [ 0x000FF17E ] = true,
    -- Galleria Supervisor's Password
    [ 0x0015DE98 ] = true,
    -- Gerald's Vault Password
    [ 0x001D83A5 ] = true,
    -- Greenetech Genetics Password
    [ 0x0016FB8B ] = true,
    -- Gwinnett Brewery Password
    [ 0x0004EBDA ] = true,
    -- HalluciGen Master Password
    [ 0x000FF378 ] = true,
    -- Henri's Terminal Password
    [ 0x0014404C ] = true,
    -- Hotel Registry Password
    [ 0x001C3AF0 ] = true,
    -- Irma's Terminal Password
    [ 0x001C3AFE ] = true,
    -- Jacob's Password
    [ 0x000E929C ] = true,
    [ 0x001965F8 ] = true,
    -- Jamaica Plain Mayor's Password
    [ 0x00111829 ] = true,
    -- Kellogg's Terminal Password
    [ 0x000A02D8 ] = true,
    -- Lab Access Password
    [ 0x000BE131 ] = true,
    -- Libertalia Password
    [ 0x001291BF ] = true,
    -- Mass Fusion Executive Lab Password
    [ 0x000B4685 ] = true,
    -- Mass. Pike Tunnel Password
    [ 0x000639D9 ] = true,
    -- National Guard Officer's Password
    [ 0x0007053C ] = true,
    -- Overseer Access Password
    [ 0x000BE152 ] = true,
    -- Overseer Door Password
    [ 0x001B2F98 ] = true,
    -- Radioactive Containment Password
    [ 0x0017660B ] = true,
    -- Reactor Terminal Password
    [ 0x001E1DA5 ] = true,
    -- Recon Bunker Access Code 429A
    [ 0x000827C9 ] = true,
    -- Security Override Password
    [ 0x0013A02C ] = true,
    -- Shaun's Terminal Password
    [ 0x001D88AC ] = true,
    -- USCG Lockup Password
    [ 0x0019FEFB ] = true,
    -- Vault 111 Key Card
    [ 0x000A16DA ] = true,
    -- Vault 81 Key Card
    [ 0x00132245 ] = true,
    -- Vault 81 Tech Password
    [ 0x001F0FB3 ] = true,
}
VIS.KEYM.Password = {
    -- Casey's Password
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04F556) ] = true,
    -- CEO's Master Password
    [ Game.GetFormFromFile("DLCCoast.esm", 0x038D90) ] = true,
    -- Control Terminal Password
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x015AA5) ] = true,
    -- Dr Hein's Passcode
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03B9D6) ] = true,
    -- Dr McDermot's Passcode
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03B9E0) ] = true,
    -- Dry Rock Gulch Safe Combination
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x046CF6) ] = true,
    -- Faraday's Program
    [ Game.GetFormFromFile("DLCCoast.esm", 0x029591) ] = true,
    -- Faraday's Terminal Password
    [ Game.GetFormFromFile("DLCCoast.esm", 0x008B28) ] = true,
    -- Forfeiture Terminal Password
    [ Game.GetFormFromFile("DLCRobot.esm", 0x00FEAC) ] = true,
    -- Medical Terminal Password
    [ Game.GetFormFromFile("DLCRobot.esm", 0x00D5E0) ] = true,
    -- Navy Base Terminal Password
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x027B2E) ] = true,
    -- Oswald's Password
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04A096) ] = true,
    -- Overboss' Password
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x00A50F) ] = true,
    -- RB-2851 Master Control Password
    [ Game.GetFormFromFile("DLCRobot.esm", 0x001D29) ] = true,
    -- Ship's Safe Combination
    [ Game.GetFormFromFile("DLCCoast.esm", 0x032C55) ] = true,
    -- Shrine Password
    [ Game.GetFormFromFile("DLCCoast.esm", 0x00F291) ] = true,
    -- Terminal Password
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03BA46) ] = true,
    -- Utility Substation Password
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x02DEEA) ] = true,
    -- VIM CEO's Password
    [ Game.GetFormFromFile("DLCCoast.esm", 0x05441B) ] = true,
}

VIS.MISC = {}
VIS.MISC.Currency = {
    -- Bottlecap
    [ 0x0000000F ] = true,
    -- Ferris Wheel Medallion
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03AC7D) ] = true,
    -- Grandchester Mansion Ticket
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x022DC0) ] = true,
    -- Mad Mulligan's Mine Cart Medallion
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03AC7A) ] = true,
    -- Nuka-Cade Ticket
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x019988) ] = true,
    -- Nuka-Cade Token
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x01998A) ] = true,
    -- Nuka-Galaxy Medallion
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03AC79) ] = true,
    -- Nuka-Racers Medallion
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03AC7C) ] = true,
    -- Pre-War Money
    [ 0x00059B02 ] = true,
    -- Subway Token
    [ 0x00059AEA ] = true,
    -- Treehouse Medallion
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03AC7E) ] = true,
    -- Vault-Tec: Among the Stars Medallion
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03AC7B) ] = true,
    -- World of Refreshment Medallion
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03AC78) ] = true,
}
VIS.MISC.Lockpick = {
    -- Bobby Pin
    [ 0x0000000A ] = true,
}
VIS.MISC.Bottle = {
    -- Amontillado Bottle
    [ 0x001BEAEE ] = true,
    -- Baby Bottle
    [ 0x0009B4BA ] = true,
    -- Beer Bottle
    [ 0x000211DD ] = true,
    -- Bourbon Bottle
    [ 0x000DEDD9 ] = true,
    [ 0x000DEDDF ] = true,
    -- Brown Bottle
    [ 0x000DF222 ] = true,
    -- Burgundy Bottle
    [ 0x000DF24D ] = true,
    -- Gwinnett Ale Bottle
    [ 0x0011EA9E ] = true,
    -- Gwinnett Brew Bottle
    [ 0x0011EA9B ] = true,
    -- Gwinnett Lager Bottle
    [ 0x0011EA9C ] = true,
    -- Gwinnett Pale Ale Bottle
    [ 0x0011EA9D ] = true,
    -- Gwinnett Pilsner Bottle
    [ 0x0011EAA0 ] = true,
    -- Gwinnett Stout Bottle
    [ 0x0011EA9F ] = true,
    -- Large Baby Bottle
    [ 0x001A899B ] = true,
    -- Liquor Bottle
    [ 0x000DF221 ] = true,
    -- Milk Bottle
    [ 0x0003B55B ] = true,
    -- Nuka Cola Bottle
    [ 0x0004835A ] = true,
    -- Rum Bottle
    [ 0x0014A138 ] = true,
    -- Small Baby Bottle
    [ 0x001A89A0 ] = true,
    -- Vodka Bottle
    [ 0x000DF031 ] = true,
    [ 0x000DEDE0 ] = true,
    -- Whiskey Bottle
    [ 0x000DEDE1 ] = true,
    [ 0x000DF032 ] = true,
    -- White Bottle
    [ 0x000DF223 ] = true,
    -- Wine Bottle
    [ 0x000DEDED ] = true,
}
VIS.MISC.Collectible = {
    -- Eyebot Model
    [ 0x001F59B5 ] = true,
    -- Mr. Gutsy Model
    [ 0x0022CB6E ] = true,
    -- Mr. Handy Model
    [ 0x0022CB6B ] = true,
    -- Nuka-Cola Lunchbox
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x043A96) ] = true,
    -- Protectron Model
    [ 0x0022CB6A ] = true,
    -- Robot Parts Model
    [ 0x0022CB6C ] = true,
    [ 0x0022CB6D ] = true,
    [ 0x0022CB6F ] = true,
    -- Sentry Bot Model
    [ 0x001F2D2D ] = true,
    -- Vault-Tec Lunchbox
    [ 0x001E55E5 ] = true,
}
VIS.MISC.Crafting = {
    [ 0x00060EC0 ] = true,
    [ 0x000628EF ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x043476) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x043477) ] = true,
}
VIS.MISC.Note = {
    -- Bond
    [ Game.GetFormFromFile("DLCCoast.esm", 0x045E25) ] = true,
    -- Contract: Shelly Tiller
    [ 0x000E1D29 ] = true,
    [ 0x000E1D2C ] = true,
    -- EyeBot Pod Schematics
    [ Game.GetFormFromFile("DLCRobot.esm", 0x0109BC) ] = true,
    -- Land Grant
    [ Game.GetFormFromFile("DLCCoast.esm", 0x045E6D) ] = true,
    -- Manuscript
    [ Game.GetFormFromFile("DLCCoast.esm", 0x045E6B) ] = true,
    -- Map to Compound
    [ 0x000E92A3 ] = true,
    -- Modified Bowling Ball Schematic
    [ Game.GetFormFromFile("DLCCoast.esm", 0x03171B) ] = true,
    -- Nuka-Berry Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04431C) ] = true,
    -- Nuka-Bombdrop Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044320) ] = true,
    -- Nuka-Cide Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04430C) ] = true,
    -- Nuka-Cooler Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044318) ] = true,
    -- Nuka-Frutti Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044323) ] = true,
    -- Nuka-Hearty Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044328) ] = true,
    -- Nuka-Lixir Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044326) ] = true,
    -- Nuka-Love Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044314) ] = true,
    -- Nuka-Power Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04431E) ] = true,
    -- Nuka-Punch Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04430E) ] = true,
    -- Nuka-Ray Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04431A) ] = true,
    -- Nuka-Rush Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044310) ] = true,
    -- Nuka-Sunrise Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044324) ] = true,
    -- Nuka-Void Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044316) ] = true,
    -- Nuka-Xtreme Recipe
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044312) ] = true,
    -- Property Deed
    [ Game.GetFormFromFile("DLCCoast.esm", 0x045E20) ] = true,
    -- Publick Occurrences
    [ 0x000A4754 ] = true,
    -- Robot Workbench Schematics
    [ Game.GetFormFromFile("DLCRobot.esm", 0x00254A) ] = true,
    [ Game.GetFormFromFile("DLCRobot.esm", 0x01133D) ] = true,
    -- Slocum's BuzzBites Recipe
    [ 0x00051388 ] = true,
    -- Spotlight Schematics
    [ Game.GetFormFromFile("DLCRobot.esm", 0x0109BB) ] = true,
}
VIS.MISC.Quest = {
    [ 0x0001ACD4 ] = true,
    [ 0x0001D95C ] = true,
    [ 0x00022264 ] = true,
    [ 0x00022266 ] = true,
    [ 0x00029167 ] = true,
    [ 0x00031AAF ] = true,
    [ 0x0003450A ] = true,
    [ 0x0003FC16 ] = true,
    [ 0x0004BAE8 ] = true,
    [ 0x0004BAE9 ] = true,
    [ 0x0004BAEA ] = true,
    [ 0x0004E3A2 ] = true,
    [ 0x0004E700 ] = true,
    [ 0x0006D0E8 ] = true,
    [ 0x000754E4 ] = true,
    [ 0x00086874 ] = true,
    [ 0x000873BF ] = true,
    [ 0x0008BB31 ] = true,
    [ 0x0009139E ] = true,
    [ 0x0009139F ] = true,
    [ 0x000986C8 ] = true,
    [ 0x00099CE7 ] = true,
    [ 0x0009A5D1 ] = true,
    [ 0x0009BC6E ] = true,
    [ 0x0009BC88 ] = true,
    [ 0x000A018C ] = true,
    [ 0x000A018E ] = true,
    [ 0x000A0190 ] = true,
    [ 0x000A50F5 ] = true,
    [ 0x000A50F7 ] = true,
    [ 0x000B1DB8 ] = true,
    [ 0x000B1DB9 ] = true,
    [ 0x000B1DBA ] = true,
    [ 0x000B254D ] = true,
    [ 0x000B2744 ] = true,
    [ 0x000B2745 ] = true,
    [ 0x000B2746 ] = true,
    [ 0x000B885E ] = true,
    [ 0x000B92DB ] = true,
    [ 0x000B9767 ] = true,
    [ 0x000C30DE ] = true,
    [ 0x000C30DF ] = true,
    [ 0x000C30E0 ] = true,
    [ 0x000C4F5B ] = true,
    [ 0x000D3CB9 ] = true,
    [ 0x000DED2A ] = true,
    [ 0x000E69AF ] = true,
    [ 0x000EB2B0 ] = true,
    [ 0x000EDE2A ] = true,
    [ 0x000FE257 ] = true,
    [ 0x000FE266 ] = true,
    [ 0x00100E20 ] = true,
    [ 0x00101048 ] = true,
    [ 0x0010DEE5 ] = true,
    [ 0x0014198E ] = true,
    [ 0x00146133 ] = true,
    [ 0x00147D5E ] = true,
    [ 0x00148B85 ] = true,
    [ 0x0017BE8B ] = true,
    [ 0x0017CC5A ] = true,
    [ 0x00190AE4 ] = true,
    [ 0x00199043 ] = true,
    [ 0x0019FCF5 ] = true,
    [ 0x0022E326 ] = true,
    [ Game.GetFormFromFile("DLCRobot.esm", 0x000881) ] = true,
    [ Game.GetFormFromFile("DLCRobot.esm", 0x000883) ] = true,
    [ Game.GetFormFromFile("DLCRobot.esm", 0x000890) ] = true,
    [ Game.GetFormFromFile("DLCRobot.esm", 0x002622) ] = true,
    [ Game.GetFormFromFile("DLCRobot.esm", 0x008AD4) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x0035C4) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x0035C5) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x00AAF6) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x00AFF6) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x0180D8) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x0180D9) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x01B0B6) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x01B0B7) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x01B0B8) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x01C702) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x01C704) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x01E3F7) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x020569) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x023B23) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x026E2F) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x026E30) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x026E31) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x026E33) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x026E38) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x02B5D9) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x034DFB) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x03A2D4) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x043B0A) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x0463B7) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x04B1A9) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x04E1CF) ] = true,
    [ Game.GetFormFromFile("DLCworkshop03.esm", 0x004825) ] = true,
    [ Game.GetFormFromFile("DLCworkshop03.esm", 0x0050EF) ] = true,
    [ Game.GetFormFromFile("DLCworkshop03.esm", 0x0050F0) ] = true,
    [ Game.GetFormFromFile("DLCworkshop03.esm", 0x0050F1) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x019987) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x01E367) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x03DA27) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x043B93) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x044F09) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04A470) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x04F646) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x053871) ] = true,
}
VIS.MISC.Resource = {
    [ 0x0006907A ] = true,
    [ 0x0006907B ] = true,
    [ 0x0006907C ] = true,
    [ 0x0006907D ] = true,
    [ 0x0006907E ] = true,
    [ 0x0006907F ] = true,
    [ 0x00069081 ] = true,
    [ 0x00069082 ] = true,
    [ 0x00069085 ] = true,
    [ 0x00069086 ] = true,
    [ 0x00069087 ] = true,
    [ 0x000731A3 ] = true,
    [ 0x000731A4 ] = true,
    [ 0x000AEC5B ] = true,
    [ 0x000AEC5C ] = true,
    [ 0x000AEC5D ] = true,
    [ 0x000AEC5E ] = true,
    [ 0x000AEC5F ] = true,
    [ 0x000AEC60 ] = true,
    [ 0x000AEC61 ] = true,
    [ 0x000AEC62 ] = true,
    [ 0x000AEC63 ] = true,
    [ 0x000AEC64 ] = true,
    [ 0x000AEC66 ] = true,
    [ 0x00106D98 ] = true,
    [ 0x00106D99 ] = true,
    [ 0x001BF72D ] = true,
    [ 0x001BF72E ] = true,
    [ 0x001BF72F ] = true,
    [ 0x001BF730 ] = true,
    [ 0x001BF732 ] = true,
}
VIS.MISC.Tool = {
    [ 0x0004D1F3 ] = true,
    [ 0x0004D1F4 ] = true,
    [ 0x0004D1F5 ] = true,
    [ 0x0004D1F6 ] = true,
    [ 0x0004D1F7 ] = true,
    [ 0x001A4AB0 ] = true,
}
VIS.MISC.Passcard = {
    [ 0x0002A6FF ] = true,
    [ 0x00046D13 ] = true,
    [ 0x0005E54A ] = true,
    [ 0x00082C07 ] = true,
    [ 0x0014DE03 ] = true,
    [ 0x0014FD7D ] = true,
    [ 0x001A58A2 ] = true,
    [ 0x001A58A6 ] = true,
}

VIS.NOTE = {}
VIS.NOTE.Game = {
    -- Atomic Command
    [ 0x0006167B ] = true,
    -- Grognak & The Ruby Ruins
    [ 0x000727FA ] = true,
    -- Pipfall
    [ 0x00072802 ] = true,
    -- Red Menace
    [ 0x000E5082 ] = true,
    -- Zeta Invaders
    [ 0x00072803 ] = true,
    -- Automatron
    [ Game.GetFormFromFile("DLCRobot.esm", 0x007B20) ] = true,
}
VIS.NOTE.Hack = {
    -- Combat Sentry Proto MKIV Holotape
    [ 0x0010B9E3 ] = true,
    -- Protectron Override Program
    [ 0x001680E3 ] = true,
    -- RobCo Defragmenter
    [ 0x000E5081 ] = true,
    -- Sentinel Site Blast Door Override
    [ 0x0014CCC7 ] = true,
    -- Spotlight Override Program
    [ 0x001128BC ] = true,
    -- Turret Override Program
    [ 0x00108B55 ] = true,
    -- turret_override.exe
    [ 0x00106E96 ] = true,
}
VIS.NOTE.Quest = {
    -- Battlefield Holotape
    [ 0x000B1DBC ] = true,
    -- Eddie Winter Holotape 0
    [ 0x000EBE77 ] = true,
    -- Eddie Winter Holotape 1
    [ 0x000EBE78 ] = true,
    -- Eddie Winter Holotape 2
    [ 0x000EBE79 ] = true,
    -- Eddie Winter Holotape 3
    [ 0x000EBE7A ] = true,
    -- Eddie Winter Holotape 4
    [ 0x000EBE7B ] = true,
    -- Eddie Winter Holotape 5
    [ 0x000EBE7C ] = true,
    -- Eddie Winter Holotape 6
    [ 0x000EBE7D ] = true,
    -- Eddie Winter Holotape 7
    [ 0x000EBE7E ] = true,
    -- Eddie Winter Holotape 8
    [ 0x000EBE7F ] = true,
    -- Eddie Winter Holotape 9
    [ 0x000D4D93 ] = true,
    -- Knight Astlin's Holotape
    [ 0x000B1DBD ] = true,
    -- Marty Bullfinch's Holotape
    [ 0x00147D52 ] = true,
    -- Network Scanner
    [ 0x00136331 ] = true,
    -- Scribe Faris' Holotape
    [ 0x000B1DBE ] = true,
    -- Silver Shroud Script
    [ 0x001B8FF9 ] = true,
}
VIS.NOTE.Settings = {
    [ Game.GetFormFromFile("DeployableTurretsPack.esp", 0x0026FF) ] = true,
    [ Game.GetFormFromFile("DynamicInteriorFogRemoval.esp", 0x001733) ] = true,
    [ Game.GetFormFromFile("Marmo1233 - Immersive Settlers.esp", 0x00B001) ] = true,
    [ Game.GetFormFromFile("TrueStormsFO4.esm", 0x004BE6) ] = true,
    [ Game.GetFormFromFile("TrueStormsFO4.esm", 0x045F3D) ] = true,
}

VIS.PERK = {}
VIS.PERK.Bobblehead = {
    -- Barter Bobblehead
    [ 0x0006167C ] = true,
    -- Big Guns Bobblehead
    [ 0x0006167D ] = true,
    -- Energy Weapons Bobblehead
    [ 0x0006167E ] = true,
    -- Explosives Bobblehead
    [ 0x0006167F ] = true,
    -- Lockpicking Bobblehead
    [ 0x00061680 ] = true,
    -- Medicine Bobblehead
    [ 0x00061681 ] = true,
    -- Melee Weapons Bobblehead
    [ 0x00061682 ] = true,
    -- Repair Bobblehead
    [ 0x00061683 ] = true,
    -- Science Bobblehead
    [ 0x00061684 ] = true,
    -- Small Guns Bobblehead
    [ 0x00061685 ] = true,
    -- Sneak Bobblehead
    [ 0x00061686 ] = true,
    -- Speech Bobblehead
    [ 0x00061687 ] = true,
    -- Unarmed Bobblehead
    [ 0x00061688 ] = true,
}
VIS.PERK.Companion = {
    -- Berserk
    [ 0x00084290 ] = true,
    -- Cloak & Dagger
    [ 0x0008530E ] = true,
    -- Close to Metal
    [ 0x001E67BD ] = true,
    -- Combat Medic
    [ 0x001E67BC ] = true,
    -- Gift of Gab
    [ 0x00178D54 ] = true,
    -- Hunter's Wisdom
    [ Game.GetFormFromFile("DLCCoast.esm", 0x018621) ] = true,
    -- Isodoped
    [ 0x00178D57 ] = true,
    -- Killshot
    [ 0x00178D50 ] = true,
    -- Know Your Enemy
    [ 0x0008428D ] = true,
    -- Lessons In Blood
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x0479EF) ] = true,
    -- Robot Sympathy
    [ 0x001EB99B ] = true,
    -- Shield Harmonics
    [ 0x000842A0 ] = true,
    -- Trigger Rush
    [ 0x001F4187 ] = true,
    -- United We Stand
    [ 0x00084298 ] = true,
}
VIS.PERK.FactionBOS = {
    -- Initiate
    [ 0x00085331 ] = true,
    -- Knight
    [ 0x000865E8 ] = true,
}
VIS.PERK.FactionRailroad = {
    -- "The Heavy"
    [ 0x0009AC99 ] = true,
    -- In The Blood
    [ 0x000A5993 ] = true,
    -- Secret Agent
    [ 0x0009AC95 ] = true,
    -- Station Master
    [ 0x0009AC98 ] = true,
}
VIS.PERK.Magazine = {
    -- Astoundingly Awesome
    [ 0x001C501E ] = true,
    [ 0x001E3CE6 ] = true,
    [ 0x00169691 ] = true,
    [ 0x0016968C ] = true,
    [ 0x00169695 ] = true,
    [ 0x00169688 ] = true,
    [ 0x0016968A ] = true,
    [ 0x00169690 ] = true,
    [ 0x0016968E ] = true,
    [ 0x00169698 ] = true,
    [ 0x00169699 ] = true,
    [ 0x00169692 ] = true,
    [ 0x00169696 ] = true,
    [ 0x00169689 ] = true,
    [ 0x00169693 ] = true,
    -- Barbarian
    [ 0x0008E3A6 ] = true,
    -- Covert Operations
    [ 0x0008E3A4 ] = true,
    -- Guns and Bullets
    [ 0x00092A82 ] = true,
    -- Islander's Almanac
    [ Game.GetFormFromFile("DLCCoast.esm", 0x050B32) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x050B33) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x050B34) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x050B35) ] = true,
    [ Game.GetFormFromFile("DLCCoast.esm", 0x050B36) ] = true,
    -- Junktown Vendor
    [ 0x000913C1 ] = true,
    -- La Coiffe
    [ 0x000B6F63 ] = true,
    -- Live & Love
    [ 0x001696A8 ] = true,
    [ 0x001696A9 ] = true,
    [ 0x001696AA ] = true,
    [ 0x001696AB ] = true,
    [ 0x001696AB ] = true,
    [ 0x001696AC ] = true,
    [ 0x001696AD ] = true,
    [ 0x001696AE ] = true,
    [ 0x001696AF ] = true,
    [ 0x001E3CFB ] = true,
    [ 0x001696B2 ] = true,
    -- Massachusetts Surgery
    [ 0x0008E3A5 ] = true,
    -- Picket Fences
    [ 0x001E3D1A ] = true,
    [ 0x001E3D1B ] = true,
    [ 0x001E3D1C ] = true,
    [ 0x001E3D1D ] = true,
    [ 0x001E3D1E ] = true,
    -- SCAV!
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x02A9F9) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x02A9FB) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x02A9FC) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x02A9FA) ] = true,
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x02A9F8) ] = true,
    -- Tesla Science
    [ 0x00092A6E ] = true,
    -- Tumblers Today
    [ 0x000913C2 ] = true,
    -- Unstoppable
    [ 0x00135F02 ] = true,
    -- Wasteland Survival
    [ 0x001C63E6 ] = true,
    [ 0x001C63E3 ] = true,
    [ 0x001C63E7 ] = true,
    [ 0x001C63EC ] = true,
    [ 0x001C63E8 ] = true,
    [ 0x001C63E4 ] = true,
    [ 0x001C63E9 ] = true,
    [ 0x001C63EB ] = true,
    [ 0x00135F08 ] = true,
}
VIS.PERK.Quest = {
    -- Ace Operator
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x009C8B) ] = true,
    -- Chosen Disciple
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x009C89) ] = true,
    -- Far Harbor Survivalist
    [ Game.GetFormFromFile("DLCCoast.esm", 0x02C9B5) ] = true,
    -- Foreknowledge
    [ 0x0018358D ] = true,
    -- Friend of The Cats
    [ 0x000D00A0 ] = true,
    -- Pach Alpha
    [ Game.GetFormFromFile("DLCNukaWorld.esm", 0x009C8A) ] = true,
    -- True Hero
    [ 0x000E1A24 ] = true,
    -- Vailt 81 Molerat Disease
    [ 0x0023AEC1 ] = true,
    -- Wired Reflexes
    [ 0x000EECC0 ] = true,
}
VIS.PERK.Temp = {
    -- Adrenaline
    [ 0x00000811 ] = true,
    -- Lover's Embrace
    [ 0x00000817 ] = true,
    [ 0x000F3C1A ] = true,
    -- Well Rested
    [ 0x00000844 ] = true,
    [ 0x0005C526 ] = true,
}

VIS.WEAP = {}
VIS.WEAP.Ammo = {
    -- Mini Nuke
    [ 0x0010E689 ] = true,
}
VIS.WEAP.Signal = {
    -- Artillery Smoke Grenade
    [ 0x0012E2CA ] = true,
    -- Homing Beacon
    [ 0x00065DEC ] = true,
    -- Institute Beacon
    [ 0x00174F8F ] = true,
    -- Synth Beacon Grenade
    [ 0x0023CACB ] = true,
    -- Synth Relay Grenade
    [ 0x000589F2 ] = true,
    -- Vertibird Signal Grenade
    [ 0x00056917 ] = true,
}

local function HasTag(formName)
    if formName then
        local firstChar = string.sub(formName, 1, 1)
        return firstChar == "{" or firstChar == "[" or firstChar == "(" or firstChar == "|"
    end
    return nil
end

local function MakeComponentsTag(formId)
    local tag = ""
    local components = {}
    local componentCount = MiscObject.GetComponents(formId, components)
    if componentCount > 0 then
        tag = "{{{" .. Form.GetName(components[1])
        for i = 2, componentCount do
            tag = tag .. ", " .. Form.GetName(components[i])
        end
        tag = tag .. "}}}"
    end
    return tag
end

patcher:registerCallback(function(formId)
    local formName = Form.GetName(formId)
    if Form.IsPlayable(formId) == true and string.len(formName) > 0 and not HasTag(formName) == true then
        local formType = Form.GetType(formId)

        if formType == ALCH then
            if VIS.ALCH.Aid[formId] == true then
                Form.SetName(formId, "(Aid) " .. formName)
            elseif VIS.ALCH.Prewar[formId] == true then
                Form.SetName(formId, "[Prewar] " .. formName)
            elseif VIS.ALCH.Quest[formId] == true then
                Form.SetName(formId, "[Quest] " .. formName)
            elseif VIS.ALCH.Device[formId] == true or
                   Form.HasKeywordString(formId, "ChemTypeStealthBoy") == true or
                   Form.HasKeywordString(formId, "DLC01ObjectTypeRepairKit") == true then
                Form.SetName(formId, "(Device) " .. formName)
            elseif Form.HasKeywordString(formId, "ObjectTypeSyringerAmmo") == true then
                Form.SetName(formId, "[Syringe] " .. formName)
            elseif Form.HasKeywordString(formId, "ObjectTypeNukaCola") == true then
                Form.SetName(formId, "[Nuka] " .. formName)
            elseif Form.HasKeywordString(formId, "ObjectTypeAlcohol") == true then
                Form.SetName(formId, "[Liquor] " .. formName)
            elseif Form.HasKeywordString(formId, "FruitOrVegetable") == true then
                Form.SetName(formId, "[Raw] " .. formName)
            elseif Form.HasKeywordString(formId, "ObjectTypeWater") == true then
                Form.SetName(formId, "(Drink) " .. formName)
            elseif Form.HasKeywordString(formId, "ObjectTypeFood") == true then
                Form.SetName(formId, "(Food) " .. formName)
            elseif Form.HasKeywordString(formId, "ObjectTypeChem") == true then
                Form.SetName(formId, "[Chem] " .. formName)
            end
        elseif formType == AMMO then
            if VIS.AMMO.Fuel[formId] == true then
                Form.SetName(formId, "(Fuel) " .. formName)
            else
                Form.SetName(formId, "(Ammo) " .. formName)
            end
        elseif formType == BOOK then
            if VIS.BOOK.Quest[formId] == true then
                Form.SetName(formId, "[Quest] " .. formName)
            elseif VIS.BOOK.Password[formId] == true then
                Form.SetName(formId, "|Password| " .. formName)
            elseif Form.HasKeywordString(formId, "PerkMagKeyword") == true then
                Form.SetName(formId, "[Perk: Mag] " .. formName)
            else
                Form.SetName(formId, "[Note] " .. formName)
            end
        elseif formType == KEYM then
            if VIS.KEYM.Passcard[formId] == true then
                Form.SetName(formId, "|Passcard| " .. formName)
            elseif VIS.KEYM.Passcard[formId] == true then
                Form.SetName(formId, "|Password| " .. formName)
            else
                Form.SetName(formId, "|Key| " .. formName)
            end
        elseif formType == MISC then
            if VIS.MISC.Currency[formId] == true then
                Form.SetName(formId, "(Currency) " .. formName .. MakeComponentsTag(formId))
            elseif VIS.MISC.Lockpick[formId] == true then
                Form.SetName(formId, "(Lockpick) " .. formName)
            elseif VIS.MISC.Bottle[formId] == true then
                Form.SetName(formId, "[Bottle] " .. formName .. MakeComponentsTag(formId))
            elseif VIS.MISC.Collectible[formId] == true then
                Form.SetName(formId, "[Collectible] " .. formName)
            elseif VIS.MISC.Crafting[formId] == true then
                Form.SetName(formId, "[Crafting] " .. formName .. MakeComponentsTag(formId))
            elseif VIS.MISC.Note[formId] == true then
                Form.SetName(formId, "[Note] " .. formName)
            elseif VIS.MISC.Quest[formId] == true then
                Form.SetName(formId, "[Quest] " .. formName)
            elseif VIS.MISC.Resource[formId] == true then
                Form.SetName(formId, "{Resource} " .. formName .. MakeComponentsTag(formId))
            elseif VIS.MISC.Tool[formId] == true then
                Form.SetName(formId, "{Tool} " .. formName .. MakeComponentsTag(formId))
            elseif VIS.MISC.Passcard[formId] == true then
                Form.SetName(formId, "|Passcard| " .. formName)
            elseif Form.HasKeywordString(formId, "BobbleheadKeyword") == true then
                Form.SetName(formId, "[Perk: Bobblehead]" .. formName)
            elseif Form.HasKeywordString(formId, "DLC05FireworkShellKeyword") == true then
                Form.SetName(formId, "(Ammo) " .. formName)
            elseif Form.HasKeywordString(formId, "ObjectTypeLooseMod") == true then
                Form.SetName(formId, "{Mod} " .. formName)
            elseif MiscObject.GetComponentCount(formId) > 0 then
                Form.SetName(formId, "{Scrap} " .. formName .. MakeComponentsTag(formId))
            else
                Form.SetName(formId, "[Trash] " .. formName)
            end
        elseif formType == NOTE then
            if VIS.NOTE.Game[formId] == true then
                Form.SetName(formId, "[Game] " .. formName)
            elseif VIS.NOTE.Hack[formId] == true then
                Form.SetName(formId, "[Hack] " .. formName)
            elseif VIS.NOTE.Quest[formId] == true then
                Form.SetName(formId, "[Quest] " .. formName)
            elseif VIS.NOTE.Settings[formId] == true then
                -- Some modders start the name with a whitespace to list it at the top.
                if string.sub(formName, 1, 1) == ' ' then
                    Form.SetName(formId, "[Settings]" .. formName)
                else
                    Form.SetName(formId, "[Settings] " .. formName)
                end
            else
                Form.SetName(formId, "[Holotape] " .. formName)
            end
        elseif formType == PERK then
            if VIS.PERK.Bobblehead[formId] == true then
                Form.SetName(formId, "(Bobblehead) " .. formName)
            elseif VIS.PERK.Companion[formId] == true then
                Form.SetName(formId, "(Companion) " .. formName)
            elseif VIS.PERK.FactionBOS[formId] == true then
                Form.SetName(formId, "(Faction: BOS) " .. formName)
            elseif VIS.PERK.FactionRailroad[formId] == true then
                Form.SetName(formId, "(Faction: Railroad) " .. formName)
            elseif VIS.PERK.Magazine[formId] == true then
                Form.SetName(formId, "(Magazine) " .. formName)
            elseif VIS.PERK.Quest[formId] == true then
                Form.SetName(formId, "(Quest) " .. formName)
            elseif VIS.PERK.Temp[formId] == true then
                Form.SetName(formId, "(Temp) " .. formName)
            end
        elseif formType == WEAP then
            if VIS.WEAP.Ammo[formId] == true then
                Form.SetName(formId, "(Ammo) " .. formName)
            elseif VIS.WEAP.Signal[formId] == true then
                Form.SetName(formId, "(Signal) " .. formName)
            elseif Form.HasKeywordString(formId, "WeaponTypeGrenade") == true or
                   Form.HasKeywordString(formId, "WeaponTypeCryoGrenade") == true or
                   Form.HasKeywordString(formId, "WeaponTypePulseGrenade") == true or
                   Form.HasKeywordString(formId, "WeaponTypePlasmaGrenade") == true or
                   Form.HasKeywordString(formId, "WeaponTypeNukaGrenade") == true then
                Form.SetName(formId, "(Grenade) " .. formName)
            elseif Form.HasKeywordString(formId, "WeaponTypeMine") == true or
                   Form.HasKeywordString(formId, "WeaponTypeCryoMine") == true or
                   Form.HasKeywordString(formId, "WeaponTypePulseMine") == true or
                   Form.HasKeywordString(formId, "WeaponTypePlasmaMine") == true or
                   Form.HasKeywordString(formId, "WeaponTypeNukaMine") == true then
                Form.SetName(formId, "(Mine) " .. formName)
            end
        end
    end
end)
