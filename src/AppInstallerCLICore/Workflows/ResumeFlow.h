// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "ExecutionContext.h"

namespace AppInstaller::CLI::Workflow
{
    // Applies a checkpoint to the context workflow.
    struct Checkpoint : public WorkflowTask
    {
        Checkpoint(std::string_view checkpointName, std::vector<Execution::Data> contextData) :
            WorkflowTask("Checkpoint"),
            m_checkpointName(checkpointName),
            m_contextData(std::move(contextData)) {}

        void operator()(Execution::Context& context) const override;

    private:
        std::string_view m_checkpointName;
        std::vector<Execution::Data> m_contextData;
    };
}
