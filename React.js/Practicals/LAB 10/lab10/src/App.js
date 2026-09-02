import React from 'react';

import InlineStyle from './components/inlinestyle';
import ExternalStyle from './components/externalstyle';
import ModuleStyle from './components/modulestyle';
import StyledButtons from './components/styledbuttons';

function App() {
  return (
    <div>

      <InlineStyle />

      <ExternalStyle />

      <ModuleStyle />

      <StyledButtons />

    </div>
  );
}

export default App;