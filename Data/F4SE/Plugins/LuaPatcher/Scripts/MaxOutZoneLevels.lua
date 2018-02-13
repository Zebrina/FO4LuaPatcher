patcher:registerCallback(function(formId, formType)
    if formType == ECZN then
        EncounterZone.SetMaxLevel(formId, 255)
    end
end)
