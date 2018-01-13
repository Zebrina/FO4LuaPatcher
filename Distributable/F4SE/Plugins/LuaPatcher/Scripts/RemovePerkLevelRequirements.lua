patcher:registerCallback(function(formId)
    if Form.GetType(formId) == PERK then
		Perk.SetLevel(formId, 0)
    end
end)
