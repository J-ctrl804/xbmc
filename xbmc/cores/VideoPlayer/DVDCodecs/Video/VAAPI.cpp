void CVAAPI::Close()
{
  if (m_display)
  {
    vaTerminate(m_display);
    m_display = nullptr;
  }
}
