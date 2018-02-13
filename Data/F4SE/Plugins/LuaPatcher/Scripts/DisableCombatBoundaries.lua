patcher:registerCallback(function(formId, formType)
    if formType == ECZN then
        EncounterZone.SetCombatBoundaryDisabled(formId, true)
    end
end)
